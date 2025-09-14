#include <iostream>

using std:: cout;
using std:: cin;
using std:: endl;

struct Node
{
    int data;
    int max;
    Node* previous;
    Node()
    {
        max = 0;
        data = 0;
        previous = nullptr;
    }
};


struct stack
{
    Node* real;

    stack()
    {
        real = nullptr;
    }
    ~stack()
    {
        while (real != nullptr)
        pop_back();
    }
    void push_back(int x)
    {
        Node* tmp = new Node;
        tmp->data = x;
        if (real == nullptr) 
        {
            tmp->max = x;
        } 
        else 
        {
            tmp->max = std::max(x, real->max);
        }
        tmp->previous = real;
        real = tmp;
    }

    void pop_back ()
    {
        if (real == nullptr) return;
        Node* tmp = real;
        real = real->previous;
        delete tmp;
    }

    int watch_back()
    {
        if (real == nullptr) return 0;
        return real->data;
    }
    int watch_max()
    {
        if (real == nullptr) return 0;
        return real->max;
    }
    bool empty() 
    {
        return real == nullptr;
    }

};


int main()
{
    int q, v;
    std::string t;
    stack A;

    cin >> q;

    for (int i=0; i<q; ++i)
    {
        cin >> t;
        if(t == "push")
        {
            cin >> v;
            A.push_back(v);
        }
        else if (t == "pop")
        {
            A.pop_back();
        }
        else if(t == "max" && !A.empty())
        {
            cout << A.watch_max() << endl;
        }
        else {continue;}
    }

    return 0;
}