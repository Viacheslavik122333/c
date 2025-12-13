#ifndef taskF
#define taskF

#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;



template <typename Tnode>
struct Node
{
    Tnode data;
    Tnode min;
    Node<Tnode>* next;

    Node(Tnode x)
    {
        min = x;
        data = x;
        next = nullptr;
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
    int push_back(Tstack x)
    {
        Node<Tstack>* tmp = new Node<Tstack>(x);

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

    void push_back2(Tstack x)
    {
        Node<Tstack>* tmp = new Node<Tstack>(x);

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
        Node<Tstack>* tmp = real;
        real = real->next;
        delete tmp;
    }

    Tstack get_back()
    {
        if (real == nullptr) return 0;
        return real->data;
    }
    Tstack get_min()
    {
        if (real == nullptr) return 0;
        return real->min;
    }
    bool empty() 
    {
        return real == nullptr;
    }

};

template <typename Tqueue>
struct queue_min
{
    stack<Tqueue> *stack_in;
    stack<Tqueue> *stack_out;

    queue_min()
    {
        stack_in = new stack<Tqueue>(); 
        stack_out = new stack<Tqueue>();
    }
    Tqueue push_back(Tqueue x)
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

    Tqueue get_min()
    {
        if(stack_in->empty() && stack_out->empty()) return 0;
        if(stack_in->empty()) return stack_out->get_min();
        if(stack_out->empty()) return stack_in->get_min();
        return std::min(stack_in->get_min(), stack_out->get_min());
    }

};


template<typename K>
void process_array()
{
    int n, t;
    K x;
    queue_min<K> A;

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) 
    {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return;
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
    return;
}

int printtex();

#endif