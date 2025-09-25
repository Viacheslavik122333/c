#include "iostream"
#include "cmath"

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


void swap (int *N, int start, int end)
{
    int tmp = N[end];
    for(int i=end; i>start; --i)
    {
        N[i] = N[i-1]; 
    }
    N[start] = tmp;
    return;
}

void fun (int h, int* N, int start, int end, int tmph)
{
    int n = end - start+1;
    if(n<3) return;
    // int tmpH = n;

    // std::cout  << " start fun : " << start << " ";
    // std::cout  << " end fun : " << end << " ";
    // std::cout  << " n fun : " << n << " :  ";
    for(int j=0; j<20; ++j)
    {
        std::cout << N[j] << " ";
    }
    std::cout  << "\n";

    for(int i=1; i<=(n-1)/2; ++i)
    {
        swap(N, start, start + i);
        tmph--;
        
        if(tmph == h)
        {
            // std::cout << "!!!!! tmph =  " << tmph << " ";
            // std::cout  << " start fun : " << start << " ";
            // std::cout  << " end fun : " << start + i << " ";
            // std::cout  << " n fun : " << n << "\n";
            // std::cout  << " end fun : " << end << " ";
            for(int j=0; j<20; ++j)
            {
                std::cout << N[j] << " ";
            }
            std::cout  << "\n";
            return;
        } 
        
        // std::cout << "\n";
        // std::cout << " tmph =  " << tmph << "\n";
    }

    std::cout << "\n\n";
    Tree tree;
    for(int i=0; i<20; ++i)
    {
        tree.insert(N[i]);
    }
    tree.print();
    std::cout << "next "<< "\n";

    fun(h, N, start+1, start + n/2, tmph);
    fun(h, N, start + (n+1)/2, end, tmph);

    return;
}
void fun2 (int h, int* N, int start, int end)
{
    int n = end - start+1;
    if(n<3) return;
    // std::cout  << " start fun : " << start << "\n";
    // std::cout  << " end fun : " << end << "\n";
    // std::cout  << " n fun : " << n << "\n";

    for(int i=1; i<=n/2; ++i)
    {
        // std::cout  << " start: " << start << "\n";
        // std::cout  << " end: " << start + i << "\n";

        swap(N, start, start + i);

        // for(int j=0; j<7; ++j)
        // {
        //     std::cout << N[j] << " ";
        // }  
        // std::cout << "\n";
    }
    // std::cout << "stop\n";
    fun2(h, N, start+1, start + n/2);
    fun2(h, N, start + 1 + n/2, end);

    return;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, h;

    std::cin >> n;
    std::cin >> h;
    ++h;

    if (h > n || n > (1 << h) - 1)
    {
        std::cout << -1  << std::endl;
        return 0;
    }
    
    if (h == n)
    {
        for(int i=n; i>0; --i)
        {
            std::cout << i << " ";
        }
        return 0;
    }
    
////////////////////////////////

    int* N = new int[n];
    for(int i=0; i<n; ++i)
    {
        N[i] = i+1;
    }

    fun (h, N, 0, n-1, n);

    // std::cout << " itog: ";
    for(int i=0; i<n; ++i)
    {
        std::cout << N[i] << " ";
    }
    std::cout << "\n\n";
    Tree tree;
    for(int i=0; i<n; ++i)
    {
        tree.insert(N[i]);
    }
    tree.print();

    return 0;
}