#include "iostream"
#include "vector"


struct Node
{
    int id;
    // dun_arr<Node*> sons;
    std::vector<Node*> sons;
};
struct Tree
{
    Node* root;
    Tree()
    {
        root == nullptr;
    }
};

int dfl(Node*v) //depth first search -- поиск в глубину
{
    int mx = 0;
    for (int i=0; i< v -> sons.size(); ++i)
    {
        mx = std::max(mx, dfl(v->sons[i]));
        return mx+1;
    }
}

//структура данных Множество 
// - уметь добавлять элементы
// - уметь удалять элементы
// - уметь искать элементы        и все это за O(log n) 

// Бинарное дерево поиска
struct Node
{
    int id;
    Node*l,*r;
    // dun_arr<Node*> sons;
    std::vector<Node*> sons;
    Node()
    {
        l = r = nullptr;
    }
};

bool _find (Node*v, int x)
{
    if(v == nullptr) return 0;
    if(v->id == x) return 1;
    if(v->id > x) return _find(v->l, x);
    if(v->id < x) return _find(v->r, x);
}

struct Tree
{
    Node* root;
    Tree()
    {
        root == nullptr;
    }
    int find (int x)
    {
        return _find(root, x);
    }
    void insert(int x)
    {
        root = _insert (root, x);
    }
};

Node* _insert (Node*v, int x)
{
    if(v == nullptr)
    {
        Node* newnode = new Node;
        newnode -> id=x;
        return newnode;
    }
    if(v->id == x) return v;
    if(v->id < x)
    {
        v->r = _insert (v -> r, x);
        return v;
    }
    if(v->id > x)
    {
        v->l = _insert (v -> l, x);
        return v;
    }
};

Node* _erase(Node*v, int x)
{
    if (v == nullptr) return nullptr;
    if(v->id < x)
    {
        v->r = _erase (v->r, x);
        return v;
    }
    if(v->id > x)
    {
        v->l = _erase (v->l, x);
        return v;
    }
    if(v->id == x)
    {
        Node* l = v->l, *r = v->r;
        delete(v);
        return _merge(l,r);
    }
}

Node* _merge (Node*l, Node*r)
{
    if(l == nullptr) return r;
    if(r == nullptr) return l;
    l->l = _merge(l->l, l->r);
    l->r = r;
    return l;
}



