#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

struct Node
{
    int data;
    int max;
    Node* next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
    ~Node()
    {
        delete next;
    }
};


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
        } 
        else 
        {
            rear->next = tmp;
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

    int get_front()
    {
        if (front == nullptr) return 0;
        return front->data;
    }

};


int main()
{
    int n, t, x;
    queue A;

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) 
    {
        std::cerr << "Не удалось открыть файл fin" << std::endl;
        return -1;
    }
    if (!fout.is_open()) 
    {
        std::cerr << "Не удалось открыть файл fout" << std::endl;
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
            fout << A.get_front() << endl;
            break;
        }
    }

    
    fin.close();
    fout.close();
    return 0;
}