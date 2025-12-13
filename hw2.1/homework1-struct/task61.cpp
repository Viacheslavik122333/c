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
        min = x;
        next = nullptr;
    }
};

void min_fun(int x, Node* tmp, Node* rear);
void min2_fun(int x, int tmp, Node* next);

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
        // cout << "o";
        if (rear == nullptr)
        {
            front = tmp;
            rear = tmp;
            // cout << "new"<< endl;
        } 
        else 
        {
            // cout << "no new" << endl;
            rear->next = tmp;
            rear = tmp;
            min_fun(x, front, front->next);
        }
        return 0;
    }

    int pop_front()
    {
        if (rear == nullptr) return -1;
        Node* tmp = front;
        if(front->next != nullptr && front->data != front->min)
        {
            min2_fun(front->data, front->min, front->next);
        }
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
        // cout << "COUT" << endl;
        if (front == nullptr) return 0;
        
        return front->min;
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
            // cout << "min = " << A.get_min() << endl;
            break;
        }
    }
 
    fin.close();
    fout.close();
    return 0;
}


void min_fun(int x, Node* front, Node* next)
{
    if(next == nullptr) return;
    int y;

    // cout << " front min = "<< front -> min << " x = "<< x << endl;

    if (x < front->min)
    {
        y=front -> min;
        // cout << " y !=! "<< y << " x !=! " << x<< endl;
        front->min = x;
    }
    else{y=x; 
    // cout << y << "!!!!!" << endl;
    }

    if (next->next == nullptr)
    {
        next->min = y;
        // cout << "y = " << y << endl;
        return;
    }

    min_fun(y, next, next->next);
}

void min2_fun(int data, int tmp, Node* next)
{
    int y;
    // cout << "da" << " next-min = "<< next->min << " data = "<< data<< endl;
    if(data == next->min)
    {
        next->min = tmp;
        // cout << "ppp = " << next->min << endl;
        return;
    }
    if(next->next == nullptr)
    {
        // cout << "gg = " << next->min << endl;
        return;
    }

    y = next->min;
    next->min = tmp;
    // cout << "y = " << y << " next->min " << next->min << endl;
    min2_fun(data, y, next->next);
}