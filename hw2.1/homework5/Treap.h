#ifndef Treep
#define Treep

#include "iostream"
#include "algorithm"
#include "utility"
#include "cmath"
#include "ctime"

namespace Treapp {
struct Node
{
    int id;
    int prior;
    Node *left, *right;
    Node(int a, int b)
    {
        id = a; prior = b;
        left = nullptr; right = nullptr; 
    }
    ~Node()
    {
        left = nullptr; 
        right = nullptr;
    }
};
}

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
        Treapp::Node* res = _lower_bound(root, x);
        if(res == nullptr) return -1;
        return res->id;
    }

    void print() // вывести дерево на экран
    { 
        _printTree(root, 0, "", true); 
    } 

private:

    Treapp::Node *root;

    Treapp::Node* _insert (Treapp::Node* v, int x, int y)
    {
        if(_find(v, x)) return v;
        std::pair<Treapp::Node*, Treapp::Node*> p = _split(v, x);
        Treapp::Node* newnode = new Treapp::Node(x, y);
        return _merge(_merge(p.first, newnode), p.second);
    }

    Treapp::Node* _erase(Treapp::Node* v, int x) 
    {
        if(!_find(v, x)) return v;
        std::pair<Treapp::Node*, Treapp::Node*> p = _split(v, x);
        std::pair<Treapp::Node*, Treapp::Node*> q = _split(p.first, x-1);
        if (q.second != nullptr) 
        {
            delete q.second;
        }
        return _merge(q.first, p.second);
    }

    bool _find (Treapp::Node*v, int x) // поиск элемента
    {
        if(v == nullptr) return 0;
        if(v->id > x) return _find(v->left, x);
        else if(v->id < x) return _find(v->right, x);
        else return 1;
    }

    Treapp::Node* _lower_bound(Treapp::Node* v, int x)
    {
        Treapp::Node* result = nullptr;
        
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

    std::pair<Treapp::Node*, Treapp::Node*> _split(Treapp::Node* v, int x) 
    {
        if(v == nullptr) { return{nullptr, nullptr};}

        if(v->id <= x) 
        {
            std::pair<Treapp::Node*, Treapp::Node*> p = _split(v->right, x);
            v->right = p.first;
            return{v, p.second};
        }
        else
        {
            std::pair<Treapp::Node*, Treapp::Node*> p = _split(v->left, x);
            v->left= p.second;
            return{p.first, v};
        }

        
    }

    Treapp::Node* _merge(Treapp::Node* l, Treapp::Node* r) 
    {
        if(l == nullptr) { return r; }
        if(r == nullptr) { return l; }
        if(l->prior > r->prior) 
        {
            l->right = _merge(l->right, r);
            return l;
        }
        else
        {
            r->left = _merge(l, r->left);
            return r;
        }
        
        
    }

    void _clear(Treapp::Node* node) 
    {
        if (node == nullptr) return;
        _clear(node->left);
        _clear(node->right);
        delete node;
    }

    void _printTree(Treapp::Node* node, int level, const std::string& prefix, bool isLeft) 
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
