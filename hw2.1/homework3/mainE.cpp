#include "iostream"
#include "climits"
#include "vector"


struct Node
{
    int id;
    int value;
    Node*l,*r;
    Node()
    {
        l = r = nullptr;
    }
    Node(int x)
    {
        value = x;
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
    
    ~Tree()
    {
        _clear(root);
    }

    bool proof()
    {
        return _proof(root, LLONG_MIN, LLONG_MAX);
    }

    void _clear (Node* v)
    {
        if(v == nullptr) {return;}
        _clear (v->l);
        _clear (v->r);
        delete v;
    }


    bool _proof(Node* node, long long min, long long max) 
    { 
        if(node == nullptr) 
        {
            return true;
        }

        if((node->value <= min) || (node->value >= max)) 
        {
            return false;
        }
        return ((_proof(node->l, min, node->value)) && (_proof(node->r, node->value, max)));
    }
    
};


int main()
{
    int n;
    std::cin >> n;

    int *N = new int[n];

    for(int i=0; i<n; ++i) std::cin >> N[i];

    std::vector<Node*> nodes(n+1);

    for(int i=1; i<n+1; ++i) 
    {
        nodes[i] = new Node(N[i-1]);
    }

    Tree A;

    for (int i=1; i<n+1; ++i) 
    {
        int a, b;
        std::cin >> a;
        std::cin >> b;
        if(a!=0) nodes[i]->l = nodes[a];
        if(b!=0) nodes[i]->r = nodes[b];
    }

    A.root = nodes[1];

    A.proof() ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl; 

    delete[] N;

    return 0;
}





 