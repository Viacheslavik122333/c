#ifndef taskC
#define taskC

#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

template <typename Tnode>
struct Node
{
    Tnode data;
    Tnode max;
    Node* previous;
    Node()
    {
        max = 0;
        data = 0;
        previous = nullptr;
    }
};

template <typename Tstack>
struct stack
{
    Node<Tstack>* real;

    stack()
    {
        real = nullptr;
    }
    ~stack()
    {
        while (real != nullptr)
        pop_back();
    }
    void push_back(Tstack x)
    {
        Node<Tstack>* tmp = new Node<Tstack>;
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
        Node<Tstack>* tmp = real;
        real = real->previous;
        delete tmp;
    }

    Tstack watch_back()
    {
        if (real == nullptr) return 0;
        return real->data;
    }
    Tstack watch_max()
    {
        if (real == nullptr) return 0;
        return real->max;
    }
    bool empty() 
    {
        return real == nullptr;
    }

};

template<typename K>
void process_array() 
{
    int q;
    K v;
    std::string t;
    stack<K> A;

    cout <<"Введите колличество операций: ";
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

    return;
}

int printtex();

#endif