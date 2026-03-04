# ifndef RB_TREE_H
# define RB_TREE_H

# include <cmath>
# include "io_status.h"

template <class T> class rb_tree;
template <class T>
class rb_tree_node : public T 
{
	enum colors 
    {
		invalid,
		red,
		black,
	};
private:
		rb_tree_node *left = nullptr;
		rb_tree_node *right = nullptr;
		rb_tree_node *parent = nullptr;
		colors color = invalid;

public:
		rb_tree_node () = default;
		rb_tree_node (const rb_tree_node& x) = delete;
		rb_tree_node (const rb_tree_node&& x)
        {
			*this = (rb_tree_node&&) x;
		}
		~rb_tree_node () 
        {
			left = nullptr;
		    right = nullptr;
		    parent = nullptr;
		}
		rb_tree_node& operator= (const rb_tree_node& x) = delete;
		rb_tree_node& operator= (rb_tree_node&& x) 
        {
			if(this != &x)
            {
                (T&&) *this = (T&&) x;
                left = x.left; right = x.right; color = x.color;
                x.left = nullptr; x.right = nullptr; x.color = invalid;
            }
            return *this;
		}
		void print (FILE *fp = stdout, bool print_color = false) 
        {
			if(print_color)
            {
				switch (color) 
                {
					case invalid: fprintf(fp, "_ ");  break;
					case red: fprintf(fp, "R ");  break;
					case black: fprintf(fp, "B ");  break;
					default: fprintf(fp, "  ");
				}
			}
			this->T::print(fp);
		}
		friend class rb_tree<T>;
};

template <class T>
class rb_tree 
{
private:
    rb_tree_node<T> *root = nullptr;
public:
    rb_tree () = default;
    rb_tree (const rb_tree& x) = delete;
    rb_tree (rb_tree&& x) 
    {
        root = x.root;  x.root = nullptr;
    }
    ~rb_tree () 
    {
        delete_tree(root);
        root = nullptr;
    }
    rb_tree& operator = (const rb_tree& x) = delete;
    rb_tree& operator= (rb_tree&& x) 
    {
        if(this != &x)
        {
            delete_tree(root);
            root = x.root;  x.root = nullptr;
        }
        return *this;
    }

    io_status insert (rb_tree_node<T>* x)
    {
        return _insert (x);
    }
    
    void print (int r = 10, FILE *fp = stdout, bool print_color = false) const 
    {
        print_tree(root, 0, r, fp, print_color);
    }

    int prof(const T *x) const 
    {
        return _prof(x);
    }

    
private:
    int _prof (const T *x) const 
    {
        rb_tree_node<T> *curr = root;

        while(curr != nullptr)
        {
            if(*x < *curr) curr = curr->left;

            else if(*x > *curr) curr = curr->right;

            else return 1;
        }
        return 0;
    }


    static void delete_tree (rb_tree_node<T> *curr) 
    {
        if(curr == nullptr) return ;
            
        delete_tree (curr->left);
        delete_tree (curr->right);
        delete curr;
    }
    static void print_tree (rb_tree_node<T> *curr, int level, int r, FILE *fp = stdout, bool print_color = false) 
    {
        if(curr == nullptr || level > r) return;
        for(int i = 0; i < level; i++) printf("  ");
            
        curr->print(fp, print_color);

        print_tree (curr->left, level + 1, r, fp);
        print_tree (curr->right, level + 1, r, fp);
    }
    void rotate_right (rb_tree_node<T> *pr) 
    {
        rb_tree_node<T> *pl = pr->left;
        pl->parent = pr->parent;
        if(pr->parent != nullptr) 
        {
            if(pr->parent->left == pr)  pr->parent->left = pl;
            else  pr->parent->right = pl;
        }
        pr->left = pl->right;
        if(pr->left != nullptr)  pr->left->parent = pr;

        pr->parent = pl;
        pl->right = pr;
    }
    void rotate_left (rb_tree_node<T> *pl) 
    {
        rb_tree_node<T> *pr = pl->right;
        pr->parent = pl->parent;
        if(pl->parent != nullptr) 
        {
            if(pl->parent->left == pl)  pl->parent->left = pr;
            else  pl->parent->right = pr;
        }
        pl->right = pr->left;
        if(pl->right != nullptr)  pl->right->parent = pl;

        pl->parent = pr;
        pr->left = pl;
    }
    
    io_status _insert (rb_tree_node<T> *x) 
    {
        if(root == nullptr)
        {
            root = x;
            root->color = rb_tree_node<T>::colors::black;
            return io_status::success;
        }

        rb_tree_node<T> *curr = root;
        rb_tree_node<T> *dad = curr->parent;

        while(curr != nullptr)
        {
            dad = curr;
            if(*x < *curr) curr = curr->left;
            else curr = curr->right;
        }
        x->parent = dad;
        if(*x < *dad)  dad->left = x;
        else  dad->right = x;
        x->color = rb_tree_node<T>::colors::red;


        while(dad != nullptr && dad->color == rb_tree_node<T>::colors::red) 
        {
            rb_tree_node<T> *grand = dad->parent;
            rb_tree_node<T> *uncle = (*dad < *grand ? grand->right : grand->left);

            if(uncle != nullptr && uncle->color == rb_tree_node<T>::colors::red)
            {
                uncle->color = rb_tree_node<T>::colors::black;
                dad->color = rb_tree_node<T>::colors::black;
                grand->color = rb_tree_node<T>::colors::red;
                x = grand;
                dad = x->parent;
            }
            else
            {
                if(grand->left == dad)
                {
                    if(dad->right == x)
                    {
                        x = dad;
                        rotate_left(x);
                        dad = x->parent;
                    }
                    dad->color = rb_tree_node<T>::colors::black;
                    grand->color = rb_tree_node<T>::colors::red;
                    rotate_right(grand);
                }
                else
                {
                    if(dad->left == x)
                    {
                        x = dad;
                        rotate_right(x);
                        dad = x->parent;
                    }
                    dad->color = rb_tree_node<T>::colors::black;
                    grand->color = rb_tree_node<T>::colors::red;
                    rotate_left(grand);
                }
                if(grand == root) root = dad;
            }
        }
        root->color = rb_tree_node<T>::colors::black;
        return io_status::success;
    }
};

#endif