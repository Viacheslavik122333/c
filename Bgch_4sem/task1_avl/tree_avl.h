#ifndef TREE_AVL_H
#define TREE_AVL_H

#include <stdio.h>
#include "io_status.h"

template <class T> class avl_tree;

template <class T> class avl_tree_node : public T
{
private:
    avl_tree_node * left = nullptr;
    avl_tree_node * right = nullptr;
    int balance = 0;
public:
    // avl_tree_node () = default; // конструктор
    avl_tree_node () : left(nullptr), right(nullptr), balance(0) {}
    avl_tree_node (const avl_tree_node& x) // конструктор копирования 
    {
        *this = (avl_tree_node&) x;
    } 
    avl_tree_node(avl_tree_node&& x) // конструктор перемещения
    {
        *this = (avl_tree_node&&) x;
    }
    ~avl_tree_node() // деструктор 
    {
        left = nullptr; right = nullptr;
    }
    avl_tree_node& operator=(const avl_tree_node& x) // оператор присваивания копированием
    {
        if(this != &x)
        {
            (T&&) *this = (T&&) x;
            left = x.left;
            right = x.right;
            balance = x.balance;
        }
        return *this;
    }
    avl_tree_node& operator=(avl_tree_node&& x) // оператор присваивания перемещением
    {
        if(this != &x)
        {
            (T&&) *this = (T&&) x;
            left = x.left; right = x.right; balance = x.balance;
            x.left = nullptr; x.right = nullptr; x.balance = 0;
        }
        return *this;
    }

    friend class avl_tree<T>;
};


template <class T> class avl_tree
{
private:
    avl_tree_node<T> * root = nullptr;
public:
    avl_tree () = default;
    avl_tree (const avl_tree& x) = delete;
    avl_tree (avl_tree&& x) 
    {
        root = x.root;  x.root = nullptr;
    }
    ~avl_tree () 
    {
        delete_tree(root);
        root = nullptr;
    }
    avl_tree& operator = (const avl_tree& x) = delete;
    avl_tree& operator= (avl_tree&& x) 
    {
        if(this != &x)
        {
            delete_tree(root);
            root = x.root;  x.root = nullptr;
        }
        return *this;
    }

    io_status read (FILE *fp = stdin, unsigned int max_read = -1) 
    {
		unsigned int count = 0;
        if(feof(fp)) return io_status::format;

        while(count < max_read)
        {
            avl_tree_node<T> x;
            io_status status = x.read(fp);

            if(feof(fp)) return io_status::success;
            else if (status != io_status::success) return status;

            avl_tree_node<T> *newnode = new avl_tree_node<T>((avl_tree_node<T>&&)x);

            if(newnode == nullptr) return io_status::memory;
            
            int flag = 0;
            io_status tmp;
            root = insert(root, newnode, flag, tmp);

            if(tmp == io_status::format) return io_status::format;
        
            count++;
            if(count == max_read) return io_status::success;
        }

        return io_status::success;
    }

    int tasks (int task_num, const int table[256])
    {
        int res = 0;
        switch(task_num) 
        {
            case 1:	return task1(root, table);
            case 2: return task2(root, table);
            case 3:
            {
                res=0;
                task3(root, res, table);
                return res;
            }    
            case 4: return task4(root, table);
            case 5:
            {
                res=0;
                task5(root, res, table);
                return res;
            }
            default: return -1;
        }
	}

    void print (int r) const 
    {
		print_tree(root, r, 0, 0);
	}

private:

    void print_tree (avl_tree_node<T> *node, int r, int level, int c) const
    {
        if(node == nullptr || level > r) return;
				
		for(int i = 0; i < level; i++) printf("  ");

        switch (c)
        {
            case -1: node->print("l"); break;
            case 1: node->print("r"); break;
            case 0: node->print(" "); break;
            default: break; 
        }

		print_tree (node->left, r, level + 1, -1);
		print_tree (node->right, r, level + 1, 1);
    }

    static void delete_tree (avl_tree_node<T> *node) // удаление дерева
    { 
		if(node == nullptr) return;
		delete_tree (node->left);
		delete_tree (node->right);
		delete node;
	}

    avl_tree_node<T>* rotate_right (avl_tree_node<T> *node, int &flag)
    {
        avl_tree_node<T> *b, *c;
        b = node->left;
        switch(b->balance) 
        {
            case -1:
                node->left = b->right;  
                b->right = node;

                node->balance = b->balance = 0;
                flag = 0;
                return b;
            case 0:
                node->left = b->right;  
                b->right = node;

                node->balance = -1;  
                b->balance = 1;
                flag = 1;
                return b;
            case 1:
                c = b->right;
                b->right = c->left;  
                c->left = b;
                node->left = c->right;  
                c->right = node;
                switch(c->balance) 
                {
                    case 0:
                        node->balance = b->balance = c->balance = 0;
                        break;
                    case 1:
                        node->balance = c->balance = 0;  b->balance = -1;
                        break;
                    case -1:
                        node->balance = 1; b->balance = c->balance = 0;
                        break;
                }
                flag = 0;
                return c;
            default:
                return nullptr;
        }
    }

    avl_tree_node<T>* rotate_left  (avl_tree_node<T> *node, int &flag)
    {
        avl_tree_node<T> *b, *c;
        b = node->right;
        switch(b->balance) 
        {
            case 1:
                node->right = b->left;  
                b->left = node;
                node->balance = b->balance = 0;
                flag = 0;
                return b;
            case 0:
                node->right = b->left;  
                b->left = node;
                node->balance = 1; b->balance = -1;
                flag = 1;
                return b;
            case -1:
                c = b->left;
                b->left = c->right; 
                c->right = b;
                node->right = c->left;  
                c->left = node;
                switch(c->balance) 
                {
                    case 0:
                        node->balance = b->balance = c->balance = 0;
                        break;
                    case -1:
                        node->balance = c->balance = 0;  
                        b->balance = 1;
                        break;
                    case 1:
                        node->balance = -1;  
                        b->balance = c->balance = 0;
                        break;
                }
                flag = 0;
                return c;
            default:
                return nullptr;
        }
    }

    avl_tree_node<T>* insert (avl_tree_node<T> *node, avl_tree_node<T> *x, int &flag, io_status &tmp)
    {
        if(node == nullptr) 
        {
            flag = 1;
            return x;
		}
        if(*x < *node)
        {
            node->left = insert(node->left, x, flag, tmp);
            if(flag == 0)
                return node;
            switch(node->balance) 
            {
                case 1:
                    node->balance = 0;  flag = 0;
                    return node;
                case 0:
                    node->balance = -1;  flag = 1;
                    return node;
                case -1:
                    return rotate_right(node, flag);
                default:
                    return nullptr;
            }
        }
        else if(*x > *node)
        {
            node->right = insert(node->right, x, flag, tmp);
            if(flag == 0)
                return node;
            switch(node->balance) 
            {
                case -1:
                    node->balance = 0;  flag = 0;
                    return node;
                case 0:
                    node->balance = 1;  flag = 1;
                    return node;
                case 1:
                    return rotate_left(node, flag);
                default:
                    return nullptr;
            }
        }
        else
        {
            tmp = io_status::format;
            return node;
        }
    }

    

    int task1(avl_tree_node<T> *node, const int table[256]) const
    {
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr && node->examination(table)) return 1;
        return task1(node->left, table) + task1(node->right, table);
    }
    int task2(avl_tree_node<T> *node, const int table[256]) const
    {
        if(node == nullptr) return 0;
        int res = tmp_max(task2(node->left, table), task2(node->right, table));
        return res + node->examination(table);
    }
    bool task3(avl_tree_node<T> *node, int &tmp, const int table[256])
    {
        if(node == nullptr) return true;
        bool vleft = task3(node->left, tmp, table);
        bool vright = task3(node->right, tmp, table);

        if(vleft && vright && node->examination(table)) 
        {
            ++tmp;
            return true;
        }
        return false;
    }
    int task4(avl_tree_node<T> *node, const int table[256]) const
    {
        int res = 0;
        int tmp = 0; 
        std::queue<avl_tree_node<T>*> q1;
        std::queue<avl_tree_node<T>*> q2;
        q1.push(node);

        while(!q1.empty())
        {
            while(!q1.empty())
            {
                auto v = q1.front();
                if(v->left != nullptr) q2.push(v->left);
                if(v->right != nullptr) q2.push(v->right);
                if(v->examination(table)) tmp++;
                q1.pop();
            }
            res = tmp_max(res, tmp);
            q1 = q2;
            q2 = {};
            tmp = 0;
        }
        return res;
    }
    int task5(avl_tree_node<T> *node, int &tmp, const int table[256])
    {
        if(node == nullptr) return 0;
        int vleft = task5(node->left, tmp, table);
        int vright = task5(node->right, tmp, table);
        int abs = (vleft>vright) ? vleft-vright : vright-vleft;

        tmp = tmp_max_abs(tmp, abs);

        return node->examination(table) + vright + vleft;
    }

    static int tmp_max (int a, int b) 
    {
        return (a > b) ? a : b;
    }
    static int tmp_max_abs (int a, int b) 
    {
        return (a-b > 0) ? a-b : b-a;
    }

    
};

#endif //TREE_AVL_H