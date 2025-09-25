#include "iostream"
#include "cmath"

struct Node
{
    int id;
    int value;
    Node*l,*r;
    Node()
    {
        l = r = nullptr;
    }
};

struct Tree
{
    Node* root;

    Tree(int x)
    {
        Node* newnode = new Node;
        newnode -> id=1;
        newnode -> value = x;
        root = newnode;
    }
    
    ~Tree()
    {
        _clear(root);
    }

    void insert(int tmp, int dad, int Id, int val) // добавлять элемент в дерево
    {
        _insert (tmp, root, dad, Id, val);
    }

    void print() 
    {
        _printTree(root, 0, "", true);
    }

    bool proof() 
    {
        Node* prev = nullptr;
        return _proof(root, prev);
    }

    void _insert(int tmp, Node* v, int dad, int Id, int val) 
    {
        if(v == nullptr) return;

        if(v->id == dad)
        {
            Node* newnode = new Node;
            newnode->id = Id;
            newnode->value = val;
            if(tmp == 1) v->l = newnode;
            else v->r = newnode;
            return;
        }

        _insert(tmp, v->l, dad, Id, val);
        _insert(tmp, v->r, dad, Id, val);
    }

    void _clear (Node* v)
    {
        if(v == nullptr) {return; }
        _clear (v->l);
        _clear (v->r);
        delete v;
    }

    void _printTree(Node* node, int level, const std::string& prefix, bool isLeft) 
    {
        if (node == nullptr) return;

        // Сначала выводим правое поддерево
        _printTree(node->r, level + 1, prefix + (isLeft ? "  │   " : "      "), false);

        // Выводим текущий узел
        std::cout << prefix;
        std::cout << (isLeft ? "  └─── " : "  ┌─── ");
        std::cout << node->id << "(" << node->value << ")"<< std::endl;

        // Затем выводим левое поддерево
        _printTree(node->l, level + 1, prefix + (isLeft ? "      " : "  │   "), true);
    }

    bool _proof(Node* node, Node*& prev) 
    {
        if (node == nullptr) return true;

        if (!_proof(node->l, prev)) return false;

        if (prev != nullptr && (prev->value >= node->value)) return false;

        prev = node;
        
        return _proof(node->r, prev);
    }
    
};


int main()
{
    int n, a, b;
    std::cin >> n;

    int *N = new int[n];
    for(int i=0; i<n; ++i) std::cin >> N[i];

    Tree A(N[0]);

    for(int i=1; i<=n; ++i)
    {
        std::cin >> a;
        std::cin >> b;
        if(a!=0) A.insert(1, i, a, N[a-1]);
        if(b!=0) A.insert(2, i, b, N[b-1]);
    }

    // A.print();

    A.proof() ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl; 

    delete[] N;

    return 0;
}





 