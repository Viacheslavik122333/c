#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

struct Node
{
    int data;
    int min;
    Node* next;

    Node(int x)
    {
        min = x;
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
    int push_back(int x)
    {
        Node* tmp = new Node(x);

        if (real == nullptr) 
        {
            tmp->min = x;
        } 
        else 
        {
            tmp->min = std::min(x, real->min);
        }
        tmp->next = real;
        real = tmp;
        return 0;
    }

    void push_back2(int x)
    {
        Node* tmp = new Node(x);

        if (real == nullptr) 
        {
            tmp->min = x;
        } 
        else 
        {
            tmp->min = std::min(x, real->min);
        }
        tmp->next = real;
        real = tmp;
    }

    void pop_back ()
    {
        if (real == nullptr) return;
        Node* tmp = real;
        real = real->next;
        delete tmp;
    }

    int get_back()
    {
        if (real == nullptr) return 0;
        return real->data;
    }
    int get_min()
    {
        if (real == nullptr) return 0;
        return real->min;
    }
    bool empty() 
    {
        return real == nullptr;
    }

};

struct queue_min
{
    stack *stack_in;
    stack *stack_out;

    queue_min()
    {
        stack_in = new stack(); 
        stack_out = new stack();
    }
    int push_back(int x)
    {
        return stack_in->push_back(x);    
    }
    int pop_front()
    {
        if(stack_in->empty() && stack_out->empty()) return -1;

        if(stack_out->empty())
        {
            while (!stack_in->empty())
            {
                stack_out->push_back2(stack_in->get_back());
                stack_in->pop_back();
            }
        }
        stack_out->pop_back();
        return 0;
    }

    int get_min()
    {
        if(stack_in->empty() && stack_out->empty()) return 0;
        if(stack_in->empty()) return stack_out->get_min();
        if(stack_out->empty()) return stack_in->get_min();
        return std::min(stack_in->get_min(), stack_out->get_min());
    }

};

int main()
{
    int n, t, x;
    queue_min A;

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) 
    {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return -1;
    }


    fin >> n;

    for (int i=0; i<n; ++i)
    {
        fin >> t;
        switch (t)
        {
        case 0:
            fin >> x;
            fout << A.push_back(x) << endl;
            break;
        case 1:
            fout << A.pop_front() << endl;
            break;

        case 2:
            fout << A.get_min() << endl;
            // cout << "min = " << A.get_min() << endl;
            break;
        }
    }
 
    fin.close();
    fout.close();
    return 0;
}