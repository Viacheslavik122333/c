#ifndef taskD
#define taskD

#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

struct Complex
{
    double re;
    double im;
    // конструкторы
    Complex ();
    Complex (double x);
    Complex (double x, double y);
    Complex(const Complex& t);
    // какие то функции
    Complex conjugation() const;
    Complex& operator=(const Complex& t);
    // арифметические операторы:
    Complex& operator+= (const Complex& t);
    Complex operator+ (const Complex& t);
    Complex& operator-= (const Complex& t);
    Complex operator- (const Complex& t);
    Complex operator* (const Complex &t);
    Complex operator/ (Complex& t);
};

std::ostream& operator<< (std::ostream& out, const Complex &x);
std::istream& operator>> (std::istream& in, Complex &x);

struct modular
{
    static const int mod = 1e9 + 7;
    int res;
    modular ();
    modular(long long t);
    modular& operator=(const modular& t);
    modular(const modular& t);
    // арифметические операторы:
    //  операторы + :
    modular& operator+= (const modular& t); 
    modular operator+ (const modular& t); 
    modular& operator++(); //префиксный --p
    modular operator++(int); //постфиксный p++
    //  операторы - :
    modular& operator-= (const modular& t); 
    modular operator- (const modular& t); 
    modular& operator--(); //префиксный
    modular operator--(int); //постфиксный
    //  операторы * и / :
    modular& operator*= (const modular &t);
    modular operator* (const modular &t);
    modular& operator/= (const modular &t);
    modular operator/(const modular& t);
    long long binpow(long long a, int n);
};

std::ostream& operator<< (std::ostream& out, const modular &x);
std::istream& operator >> (std::istream& in, modular &x);


template <typename Tnode>
struct Node
{
    Tnode data;
    Tnode max;
    Node<Tnode>* next;
    Node(Tnode x)
    {
        data = x;
        next = nullptr;
    }
    ~Node()
    {
        delete next;
    }
};

template <typename Tqueue>
struct queue
{
    Node<Tqueue>* front; // начало очереди
    Node<Tqueue>* rear;  // конец очереди

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


    int push_back(Tqueue x)
    {
        Node<Tqueue>* tmp = new Node<Tqueue>(x);
        
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
        Node<Tqueue>* tmp = front;
        front = front -> next;
        if (front == nullptr) 
        {
            rear = nullptr;
        }
        tmp->next = nullptr;
        delete tmp;
        return 0;
    }

    Tqueue get_front()
    {
        if (front == nullptr) return 0;
        return front->data;
    }

};


template<typename K>
void process_array()
{
    int n, t;
    K x;
    queue<K> A;

    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) 
    {
        std::cerr << "Не удалось открыть файл fin" << std::endl;
        return;
    }
    if (!fout.is_open()) 
    {
        std::cerr << "Не удалось открыть файл fout" << std::endl;
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
            fout << A.get_front() << endl;
            break;
        }
    }
    
    fin.close();
    fout.close();
    return;
}


int printtex();

#endif