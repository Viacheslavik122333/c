#ifndef upTreep
#define upTreep

#include "iostream"
#include "algorithm"
#include "utility"
#include "cmath"
#include "ctime"

struct Node
{
    int id;
    int prior;
    int size; // кол-во элементов в поддереве
    Node *left, *right;
    Node(int a, int b)
    {
        id = a; prior = b; size = 1;
        left = nullptr; right = nullptr; 
    }
    ~Node()
    {
        left = nullptr; 
        right = nullptr;
    }
};

struct Treap
{
public:

    Treap() {root = nullptr; }

    ~Treap()
    {
        _clear(root);
    }

    void insert(int x) // добавлять элемент в дерево
    {
        int priority = rand(); // случайный приоритет
        root = _insert (root, x, priority);
    }

    void erase (int x) // удалить элемент из дерева
    { 
        root = _erase(root, x); 
    } 

    bool find (int x) // есть ли элемент в дереве
    {
        return _find(root, x);
    }

    int lower_bound (int x)
    {
        Node* res = _lower_bound(root, x);
        if(res == nullptr) return -1;
        return res->id;
    }

    int k_statistics (int k)
    {
        return _k_statistics(root, k);
    }

    int quantity (int x)
    {
        int res=0;
        _quantity(root, x, res);
        return res;
    }

    void print() // вывести дерево на экран
    { 
        _printTree(root, 0, "", true); 
    } 

private:

    Node *root;

    int _k_statistics(Node* v, int k) 
    {
        Node* tmp = v;  

        while (tmp != nullptr) 
        {
            int left_s = (tmp->left == nullptr) ? 0 : tmp->left->size;
            
            if (k == left_s + 1) 
            {
                return tmp->id;
            }
            else if (k <= left_s) 
            {
                tmp = tmp->left;
            }
            else // k > left.s
            {
                k -= left_s + 1;
                tmp = tmp->right;
            }
        }
        
        return -1; // не найден :(
    }

    Node* _quantity (Node* v, int x, int &res)
    {
        if(v==nullptr) return v;
        if(v->id > x)
        {
            return _quantity(v->left, x, res);
        }
        else if (v->id < x)
        {
            res += (v->left == nullptr ? 0 : v->left->size) + 1;
            return _quantity(v->right, x, res);
        }
        else  //v->id = x
        {
            res += (v->left == nullptr ? 0 : v->left->size);
            return v;
        }
        
    }

    void _up_size(Node* v)
    {
        if (v != nullptr) 
        {
            int left_s = (v->left == nullptr) ? 0 : v->left->size;
            int right_s = (v->right == nullptr) ? 0 : v->right->size;
            v->size = left_s + right_s + 1;
        }
    }
    
    Node* _insert (Node*v, int x, int y)
    {
        if(_find(v, x)) return v;
        std::pair<Node*, Node*> p = _split(v, x);
        Node* newnode = new Node(x, y);
        return _merge(_merge(p.first, newnode), p.second);
    }

    Node* _erase(Node* v, int x) 
    {
        if(!_find(v, x)) return v;
        std::pair<Node*, Node*> p = _split(v, x);
        std::pair<Node*, Node*> q = _split(p.first, x-1);
        if (q.second != nullptr) 
        {
            delete q.second;
        }
        return _merge(q.first, p.second);
    }

    bool _find (Node*v, int x) // поиск элемента
    {
        if(v == nullptr) return 0;
        if(v->id > x) return _find(v->left, x);
        else if(v->id < x) return _find(v->right, x);
        else return 1;
    }

    Node* _lower_bound(Node* v, int x)
    {
        Node* result = nullptr;
        
        while (v != nullptr) 
        {
            if (v->id >= x)
            {
                result = v;
                v = v->left;
            } 
            else 
            {
                v = v->right;
            }
        }
        
        return result;
    }

    std::pair<Node*, Node*> _split(Node* v, int x) 
    {
        if(v == nullptr) { return{nullptr, nullptr};}

        if(v->id <= x) 
        {
            std::pair<Node*, Node*> p = _split(v->right, x);
            v->right = p.first;
            _up_size(v);
            return{v, p.second};
        }
        else
        {
            std::pair<Node*, Node*> p = _split(v->left, x);
            v->left= p.second;
            _up_size(v);
            return{p.first, v};
        }

        
    }

    Node* _merge(Node* l, Node* r) 
    {
        if(l == nullptr) { return r; }
        if(r == nullptr) { return l; }
        if(l->prior > r->prior) 
        {
            l->right = _merge(l->right, r);
            _up_size(l);
            return l;
        }
        else
        {
            r->left = _merge(l, r->left);
            _up_size(r);
            return r;
        }
    }

    void _clear(Node* node) 
    {
        if (node == nullptr) return;
        _clear(node->left);
        _clear(node->right);
        delete node;
    }

    void _printTree(Node* node, int level, const std::string& prefix, bool isLeft) 
    {
        if (node == nullptr) return;

        // Сначала выводим правое поддерево
        _printTree(node->right, level + 1, prefix + (isLeft ? "│   " : "    "), false);

        // Выводим текущий узел
        std::cout << prefix;
        std::cout << (isLeft ? "└─── " : "┌─── ");
        std::cout << node->id << "(" << node ->prior << ")" << std::endl;

        // Затем выводим левое поддерево
        _printTree(node->left, level + 1, prefix + (isLeft ? "    " : "│   "), true);
    }
};

#endif
