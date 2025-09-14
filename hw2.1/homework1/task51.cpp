#include <iostream>
#include <fstream>
#include <sstream>

using std:: cout;
using std:: cin;
using std:: endl;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = nullptr;
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
        Node* tmp = new Node(x);
        tmp->next = real;
        real = tmp;
    }

    int pop_back ()
    {
        if (real == nullptr) return 0;
        Node* tmp = real;
        int x = tmp -> data;
        real = real->next;
        delete tmp;
        return x;

    }

    int get_back()
    {
        if (real == nullptr) return 0;
        return real->data;
    }
    bool empty() 
    {
        return real == nullptr;
    }
};

int main() 
{
    std::string input;
    std::getline(std::cin, input);
    
    std::istringstream line(input); // делим на элементы 
    std::string x;

    stack A;
    int a, b;
    
    int n = 0;
    
    while (line >> x) 
    { 
        if(x == "+")
        {
            b = A.pop_back();
            a = A.pop_back();
            A.push_back(a+b);

        } 
        else if(x == "-")
        {
            b = A.pop_back();
            a = A.pop_back();
            A.push_back(a-b);
        }
        else if(x == "*")
        {
            b = A.pop_back();
            a = A.pop_back();
            A.push_back(a*b);
        }
        else if(x == "/")
        {
            b = A.pop_back();
            a = A.pop_back();
            A.push_back(a/b);
        }
        else
        {
            A.push_back( std::stoi(x) );
        }

        n++;
    }
    // cout << "Ответ: " << A.get_back() << endl; 
    cout << A.get_back() << endl; 
    
    return 0;
}