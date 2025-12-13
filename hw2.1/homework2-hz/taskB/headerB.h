#ifndef taskB
#define taskB

#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

struct Node
{
    int data;
    Node* previous;
    Node();
};


struct stack
{
    Node* real;

    stack();
    ~stack();
    void push_back(int x);
    void pop_back ();
    int watch_back();
};



#endif