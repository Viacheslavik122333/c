#include "iostream"
#include "vector"

struct Node
{
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

    Node* _insert (Node*v, int x, bool& deleted) // вставлять элемент
    {
        if(v == nullptr)
        {
            Node* newnode = new Node;
            newnode -> value=x;
            deleted = true;
            return newnode;
        }

        if (x < v->value)
        {
            v->l = _insert(v->l, x, deleted);
            return v;
        }
        else if (x > v->value)
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
};

Node* fun(Tree &tree, int n, int h, std::vector<int> &solve, Node*v)
{
    if(h == 0 || v == nullptr)
    {
        return v;
    }
    int res = std::pow(2,h-1);
    while (res>n)
    {
        --res;
    }
    solve.push_back(res);
    tree.insert(res);
    v->l = fun (tree, n, h-1, solve, v->l);
    v->r = fun (tree, n, h-1, solve, v->r);






    return;
}

using std::vector;

vector<int> balanced_order(int start, int end) 
{
    if (start > end) return {};
    int mid = (start + end) / 2;
    vector<int> left = balanced_order(start, mid - 1);
    vector<int> right = balanced_order(mid + 1, end);
    vector<int> res;
    res.push_back(mid);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}



void fun1(int x, std::vector<int> &solve)
{
    solve.push_back(x);
    if(x == 1) return;
    fun1(x/2, solve);
    return;
}



int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, h;
    ++h;
    Tree tree;

    std::cin >> n >> h;

    if(h > n || n > std::pow(2,h)-1)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (h == n)
    {
        for(int i=n; i>0; ++i)
        {
            std::cout << i << " ";
        }
        return 0;
    }
    
////////////////////////////////

    std::vector<int> solve (n);

    int res = std::pow(2,h-1);

    while (res>n)
    {
        --res;
    }

    solve.push_back(res);

    fun1(std::pow(2,h-2), solve);






    tree.insert(std::pow(2,h-2));

    // fun(n, h, solve);

    for (int i=0; i<n; ++i)
    {
        
    }

    return 0;
}