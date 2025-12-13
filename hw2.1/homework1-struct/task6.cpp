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
        data = x;
        next = nullptr;
    }
};

void min_fun(int x, Node* tmp, Node* rear);

struct queue
{
    Node* front; // начало очереди
    Node* rear;  // конец очереди

    queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    ~queue()
    {
        while (front != nullptr)
        pop_front();
    }

    int push_back(int x)
    {
        Node* tmp = new Node(x);
        
        if (rear == nullptr)
        {
            front = tmp;
            rear = tmp;
            rear -> min = x;
        } 
        else 
        {
            rear->next = tmp;
            min_fun(x, front, front->next);
            rear = tmp;
        }
        return 0;
    }

    int pop_front()
    {
        if (rear == nullptr) return -1;
        Node* tmp = front;
        front = front -> next;
        if (front == nullptr) 
        {
            rear = nullptr;
        }
        tmp->next = nullptr;
        delete tmp;
        return 0;
    }

    int get_min()
    {
        if (rear == nullptr) return 0;
        return rear->min;
    }

};



int main()
{
    int n, t, x;
    queue A;

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
            break;
        }
    }
 
    
    fin.close();
    fout.close();
    return 0;
}


void min_fun(int x, Node* front, Node* next)
{
    int y;
    if (next == nullptr)
    {
        front->min = x;
        cout << "y = " << x << endl;
        return;
    }

    if (x > front->min)
    {
        y=front -> min;
        cout << y << endl;
        front->min = x;
    }
    else 
    {
        y = x;
    }
    min_fun(y, next, next->next);
}