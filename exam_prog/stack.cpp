#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

struct Node
{
    int data;
    Node* previous;
    Node()
    {
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

};