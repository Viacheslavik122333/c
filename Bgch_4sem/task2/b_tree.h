# ifndef B_TREE_H
# define B_TREE_H

# include <cmath>
# include "io_status.h"

template <class T> class b_tree;

template <class T>
class b_tree_node 
{
private:
    T *values = nullptr;
    int size = 0;
    b_tree_node **children = nullptr; ///< 2*m+1
public:
    b_tree_node () = default;
    b_tree_node (const b_tree_node&) = delete;
    b_tree_node(b_tree_node&& x) : values(x.values), size(x.size), children(x.children)
    {
        x.values = nullptr;
        x.children = nullptr;
        x.size = 0;
    }
    ~b_tree_node () 
    {
        delete[] values;
        delete[] children;
    }
    void print (int p = 0, FILE *fp = stdout) const 
    {
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < p; j++) fprintf(fp, "  ");
            fprintf(fp, "v[%d]:", i + 1);
            // fprintf(fp, "%d ", values[i]);
            values[i].print(fp);
        }
    }

    int search (const T& x) const // бин поиск 
    { 
        int l = 0, r = size, m;
        while(l != r)
        {
            m = (l + r) / 2;
            if(values[m] < x) l = m + 1;
            else r = m;
        }
        return l;
    }
    
    
    friend class b_tree<T>;
private:

    void add_v (T& x, b_tree_node<T>* down, int j) 
    {
        for(int i = size; i > j; --i)
        {
            values[i] = static_cast<T&&>(values[i - 1]);
            children[i + 1] = children[i];
        }
        values[j] = static_cast<T&&>(x);
        children[j + 1] = down;
        size++;
    }
    io_status init (int m) 
    {
        values = new T[2*m];
        if(values == nullptr) return io_status::memory;
            
        children = new b_tree_node<T>*[2*m + 1];
        if(children == nullptr) return io_status::memory;
        return io_status::success;
    }
    
    
};

template <class T> class b_tree
{
private:
    int m;
	b_tree_node<T> *root = nullptr;
public:
    b_tree (int i = 0) { m = i; }
	~b_tree () 
    {
		_delete_tree (root);
	}

    void print (int r = 10, FILE *fp = stdout) const 
    {
		_print_tree (root, 0, r, fp);
	}

    io_status insert (T& x)
    {
        return _insert (x);
    }

    int prof(const T& x) const 
    {
        return _prof(root, x);
    }
    

private:
    int _prof(b_tree_node<T>* node, const T& x) const
    {
        if (node == nullptr) return 0;
        int pos = node->search(x);
        if (pos < node->size && node->values[pos] == x) return 1;
        return _prof(node->children[pos], x);
    }
    static void _delete_tree (b_tree_node<T> *curr) 
    {
        if(curr == nullptr) return ;
        for(int i = 0; i <= curr->size; i++) _delete_tree(curr->children[i]);
        delete curr;
    }

    static void _print_tree (b_tree_node<T> *curr, int level, int r, FILE *fp = stdout) 
    {
        if(curr == nullptr || level > r) return;
        curr->print (level, fp);

        for(int i = 0; i <= curr->size; i++)
        {
            if(curr->children[i] && level + 1 <= r) 
            {
                for(int j = 0; j < level; j++) fprintf(fp, "    ");
                fprintf(fp, "\n");
                _print_tree(curr->children[i], level + 1, r, fp);
            }
        }
    }

    io_status _insert (T& x) 
    {
        if(root == nullptr) // дерево пусто
        {
            
            root = new b_tree_node<T>();

            if(root == nullptr) return io_status::memory;

            if(root->init(m) != io_status::success)
            {
                delete root;
                return io_status::memory;
            }

            root->values[0] = std::move(x);
            root->size = 1;
            
            return io_status::success;
        }

        b_tree_node<T> *curr = root;
        b_tree_node<T> *down = nullptr;

        io_status r = _insert_subtree(curr, down, x, m);

        if(r != io_status::create) return r;


        b_tree_node<T> *p = new b_tree_node<T>();
        if(p == nullptr) return io_status::memory;

        if(p->init(m) != io_status::success)
        {
            delete p;
            return io_status::memory;
        }

        p->values[0] = std::move(x);
        p->children[0] = curr;
        p->children[1] = down;
        p->size = 1;
        root = p;
        return io_status::success;
	}
    

    static io_status _insert_subtree (b_tree_node<T>*& curr, b_tree_node<T>*& down, T& x, int m) 
    {

        int index = curr->search(x);
        if (index < curr->size && curr->values[index] == x) return io_status::success;

        b_tree_node<T> *p = curr->children[index];

        if(p != nullptr)
        { 
            io_status r = _insert_subtree(p, down, x, m);
            if(r != io_status::create) return r;
        }
        else down = nullptr;

        if(curr->size < 2*m) // просто добавляем (есть место)
        {
            curr-> add_v(x, down, index);
            return io_status::success;
        }
        else // нет места, разделяем
        {
            T* tmp_value = new T[2*m + 1];
            b_tree_node<T>** tmp_children = new b_tree_node<T>*[2*m + 2];

            for (int i = 0; i < curr->size; ++i)
            {
                tmp_value[i] = std::move(curr->values[i]);
            } 

            for (int i = 0; i <= curr->size; ++i) 
            {
                tmp_children[i] = curr->children[i];
                curr->children[i] = nullptr;
            }

            for (int i = curr->size; i > index; --i) 
            {
                tmp_value[i] = std::move(tmp_value[i-1]);
                tmp_children[i+1] = tmp_children[i];
            }

            tmp_value[index] = std::move(x);
            tmp_children[index+1] = down;

            T median = std::move(tmp_value[m]);

            b_tree_node<T>* new_node = new b_tree_node<T>();

            if (new_node == nullptr) 
            {
                delete[] tmp_value;
                delete[] tmp_children;
                return io_status::memory;
            }
            
            if (new_node->init(m) != io_status::success) 
            {
                delete[] tmp_value;
                delete[] tmp_children;
                delete new_node;
                return io_status::memory;
            }

            for (int i = 0; i < m; ++i) 
            { 
                curr->values[i] = std::move(tmp_value[i]);
                curr->children[i] = tmp_children[i];
            }
            curr->children[m] = tmp_children[m];
            curr->size = m;

            for (int i = 0; i < m; ++i) // правая половина
            {
                new_node->values[i] = std::move(tmp_value[m + 1 + i]);
                new_node->children[i] = tmp_children[m + 1 + i];
            }
            new_node->children[m] = tmp_children[2*m + 1];
            new_node->size = m;

            x = std::move(median);
            down = new_node;

            delete[] tmp_value;
            delete[] tmp_children;
            return io_status::create;
        }

        return io_status::success;
    }

};

#endif