#include "iostream"
#include "vector"

struct Node
{
    int id;
    Node*l,*r;
    // std::vector<Node*> sons;
    Node()
    {
        l = r = nullptr;
    }
};

struct Tree
{
    Node* root;
    Tree()
    {
        root = nullptr;
    }

    int insert(int x) // добавлять элемент в дерево
    {
        bool del=0;
        root = _insert (root, x, del);
        return del ? 1 : 0;
    }

    int erase (int x) // удалить элемент из дерева
    {
        bool del=0;
        root = _erase(root, x, del);
        return del ? 1 : 0;
    }

    int find (int x) // есть ли элемент в дереве
    {
        return _find(root, x);
    }

    void print() 
    {
        _printTree(root, 0, "", true);
    }

    Node* _insert (Node*v, int x, bool& deleted) // вставлять элемент
    {
        if(v == nullptr)
        {
            Node* newnode = new Node;
            newnode -> id=x;
            deleted = true;
            return newnode;
        }

        if (x < v->id)
        {
            v->l = _insert(v->l, x, deleted);
            return v;
        }
        else if (x > v->id)
        {
            v->r = _insert(v->r, x, deleted);
            return v;
        }
        else
        {
            deleted = false;
            return v;
        }
    }

    Node* _findMin(Node* v) 
    {
        while (v != nullptr && v->l != nullptr) 
        {
            v = v->l;
        }
        return v;
    }

    Node* _erase(Node* v, int x, bool& deleted) 
    {
        if (v == nullptr) 
        {
            deleted = false;
            return nullptr;
        }
        
        if (x < v->id) 
        {
            v->l = _erase(v->l, x, deleted);
            return v;
        } 
        else if (x > v->id) 
        {
            v->r = _erase(v->r, x, deleted);
            return v;
        } 
        else // нашли x
        {
            deleted = true;
            
            if (v->l == nullptr) 
            {
                Node* tmp = v->r;
                delete v;
                return tmp;
            } 
            else if (v->r == nullptr) 
            {
                Node* tmp = v->l;
                delete v;
                return tmp;
            }
            
            Node* tmp = _findMin(v->r);
            
            v->id = tmp->id;
            
            bool tmpDeleted;
            v->r = _erase(v->r, tmp->id, tmpDeleted);
        
            return v;
        }
    }

    bool _find (Node*v, int x) // поиск элемента
    {
        if(v == nullptr) return 0;
        if(v->id > x) return _find(v->l, x);
        else if(v->id < x) return _find(v->r, x);
        else return 1;
    }

    void _printTree(Node* node, int level, const std::string& prefix, bool isLeft) 
    {
        if (node == nullptr) return;

        // Сначала выводим правое поддерево
        _printTree(node->r, level + 1, prefix + (isLeft ? "│   " : "    "), false);

        // Выводим текущий узел
        std::cout << prefix;
        std::cout << (isLeft ? "└── " : "┌── ");
        std::cout << node->id << std::endl;

        // Затем выводим левое поддерево
        _printTree(node->l, level + 1, prefix + (isLeft ? "    " : "│   "), true);
    }
};

int main()
{
    int n;
    std::cin >> n;
    Tree tree;


    return 0;
}