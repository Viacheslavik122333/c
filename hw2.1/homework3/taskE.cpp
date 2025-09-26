#include <iostream>
#include <vector>
#include <climits>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    int id;
    Node* left;
    Node* right;

    Node() {
        id = 0;
        left = nullptr;
        right = nullptr;
    }
    
    Node(int _id) {
        id = _id;
        left = nullptr;
        right = nullptr;
    }
};

struct BinaryTree 
{
    Node* root;

    BinaryTree() 
    {
        root = nullptr;
    }

    void clear(Node* node) 
    {
        if (node != nullptr) 
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    ~BinaryTree() {
        clear(root);
    }

    int _check(Node* node, long long min, long long max) { // не знаю как реализовать без min, max, поскольку нужно проверять что нода находится в диапазоне, определяемым предыдущими нодами, поэтому в первом приближении заполню максимально возможными числами (в идеале это должно быть +inf и -inf, для того чтобы эти числа были достаточно больними, буду использовать лонг лонг) 
        if(node == nullptr) {
            return 1;
        }

        if((node->id <= min) || (node->id >= max)) {
            return 0;
        }
        return ((_check(node->left, min, node->id)) && (_check(node->right, node->id, max)));
    }

    int check() {
        return _check(root, LLONG_MIN, LLONG_MAX);
    }
};

int main(void) {
    BinaryTree tree;
    int n;
    int res;
    cin >> n;
    vector<Node*> nodes(n+1);
    vector<int> values(n);

    for(int i=0; i<n; ++i) {
        cin >> values[i];
    }

    for(int i=1; i<n+1; ++i) {
        nodes[i] = new Node(values[i-1]);
    }

    for (int i=1; i<n+1; ++i) {
        int l, r;
        cin >> l >> r;
        nodes[i]->left = nodes[l];
        nodes[i]->right = nodes[r];
    }

    tree.root = nodes[1];
    res = tree.check();
    if(res == 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}