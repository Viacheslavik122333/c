#include "headerB.h"

Node::Node()
{
    data = 0;
    previous = nullptr;
}

stack::stack()
{
    real = nullptr;
}
stack::~stack()
{
    while (real != nullptr)
    pop_back();
}
void stack::push_back(int x)
{
    Node* tmp = new Node;
    tmp->data = x;
    tmp->previous = real;
    real = tmp;
}
void stack::pop_back ()
{
    if (real == nullptr) return;
    Node* tmp = real;
    real = real->previous;
    delete tmp;
}
int stack::watch_back()
{
    if (real == nullptr) return 0;
    return real->data;
}
