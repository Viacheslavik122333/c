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


int main()
{
    int n, t, N=1;
    stack A, B;
    // std::ifstream fin("input.txt");
    // std::ofstream fout("output.txt");

    // if (!fin.is_open() || !fout.is_open()) 
    // {
        // std::cerr << "Не удалось открыть файл" << std::endl;
        // return -1;
    // }

    cin >> n;


    for (int i=0; i<n; ++i)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            A.push_back(N);
            ++N;
            break;
        case 2:
            B.push_back(N);
            ++N;
            break;

        case 3:
            if (B.real == nullptr || (A.real != nullptr && A.watch_back() < B.watch_back())) {
                A.pop_back();
            } else {
                B.pop_back();
            }
            break;
        }
    }

    cout << A.watch_back() + B.watch_back() << endl;

    // fin.close();
    // fout.close();
    return 0;
}