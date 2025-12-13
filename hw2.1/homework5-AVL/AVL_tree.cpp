#include "iostream"
#include "algorithm"
#include "utility"
#include "cmath"
#include "ctime"

struct Node
{
    int id;
    unsigned char height; // высота поддерева с корнем в данном узле
	Node* left; // левое поддерево
	Node* right; // правое поддерево

	Node(int k) { id = k; left = right = 0; height = 1; }
    ~Node()
    {
        left = nullptr; 
        right = nullptr;
    }
};

struct AVL_tree
{
public:

    AVL_tree() {root = nullptr;}

    ~AVL_tree()
    {
        _clear(root);
    }

    void insert(int x) // добавлять элемент в дерево
    {
        root = _insert (root, x);
    }

    void erase (int x) // удалить элемент из дерева
    { 
        root = _erase(root, x); 
    } 

    bool find (int x)
    {
        return _find(root, x);
    }

    void print() // вывести дерево на экран
    { 
        _printTree(root, 0, "", true); 
    } 
private:

    Node *root;

    Node* _insert(Node* v, int x) // вставка в дерево элемента id = x
    {
        if(v == nullptr)
        {
            Node* newnode = new Node(x);
            return newnode;
        }
        if( x<v->id ) v->left = _insert(v->left, x);
		
	    else v->right = _insert(v->right,x);
		
	    return _balance(v); // балансировка дерева после вставки
    }

    Node* _balance(Node* v) // балансировка узла v
    {
        _tmp_height(v);

        if( _bfactor(v) == 2 ) // правое - левое = 2
        {
            if( _bfactor(v->right) < 0 )
            {
                v->right = _smallrotateright(v->right);
            }
            return _smallrotateleft(v);
        }
        if( _bfactor(v) == -2 ) // правое - левое = -2
        {
            if(_bfactor(v->left) > 0 ) 
            {
                v->left = _smallrotateleft(v->left);
            }
            return _smallrotateright(v);
        }
        return v; // балансировка не нужна
    }

    Node* _smallrotateright(Node* v) // малый поворот направо
    {
        Node* w = v->left;
        v->left = w->right;
        w->right = v;
        _tmp_height(v);
        _tmp_height(w);
        return w;
    }

    Node* _smallrotateleft(Node* v) // малый поворот налево
    {
        Node* w = v->right;
        v->right = w->left;
        w->left = v;
        _tmp_height(v);
        _tmp_height(w);
        return w;
    }

    Node* _erase(Node* v, int x)
    {
        if( v == nullptr ) return 0;

        if( x < v->id ) v->left = _erase(v->left, x);
            
        else if( x > v->id ) v->right = _erase(v->right, x);	

        else // ура, нашли что надо удалить
        {
            Node* w = v->left;
            Node* r = v->right;
            delete v;

            if( r==nullptr ) return w; // тогда w это просто листок

            Node* min = _findmin(r);

            min->right = _deletemin(r);

            min->left = w;

            return _balance(min);
        }
        return _balance(v);
    }

    unsigned char _height(Node* v) { return v ? (v->height) : 0; } // вычисление height

    void _tmp_height(Node* v)
    {
        unsigned char hl = _height(v->left);
        unsigned char hr = _height(v->right);
        v->height = ((hl > hr) ? hl : hr)+1;
    }

    int _bfactor(Node* v) { return (_height(v->right)) - (_height(v->left)); } // вычисляет balance поддеревьев

    Node* _findmin(Node* v) // поиск узла с минимальным эл 
    {
        return v->left ? _findmin (v->left) : v;
    }

    Node* _deletemin(Node* v) // удаление узла с минимальным эл
    {
        if( v->left == 0 ) return v->right;
            
        v->left = _deletemin(v->left);
        return _balance(v);
    }

    bool _find (Node*v, int x) // поиск элемента
    {
        if(v == nullptr) return false;
        if(v->id > x) return _find(v->left, x);
        else if(v->id < x) return _find(v->right, x);
        else return true;
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
        std::cout << node->id << std::endl;

        // Затем выводим левое поддерево
        _printTree(node->left, level + 1, prefix + (isLeft ? "    " : "│   "), true);
    }

    // spasite!
};

int main()
{
    AVL_tree tree;
    tree.insert(40);
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(4);
    tree.insert(50);
    tree.print();
    tree.erase(5);
    tree.print();


    return 0;
}