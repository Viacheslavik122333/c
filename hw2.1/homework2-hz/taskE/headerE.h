#ifndef taskE
#define taskE

#include <iostream>
#include <fstream>
#include <sstream>
#include <type_traits>

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
    Node* next;

    Node(Tnode x)
    {
        data = x;
        next = nullptr;
    }
};

template <typename Tqueue>
struct stack
{
    Node<Tqueue>* real;

    stack()
    {
        real = nullptr;
    }
    ~stack()
    {
        while (real != nullptr)
        pop_back();
    }
    void push_back(Tqueue x)
    {
        Node<Tqueue>* tmp = new Node<Tqueue>(x);
        tmp->next = real;
        real = tmp;
    }

    Tqueue pop_back ()
    {
        if (real == nullptr) return 0;
        Node<Tqueue>* tmp = real;
        Tqueue x = tmp -> data;
        real = real->next;
        delete tmp;
        return x;

    }

    Tqueue get_back()
    {
        if (real == nullptr) return 0;
        return real->data;
    }
    bool empty() 
    {
        return real == nullptr;
    }
};

// Для int, double, modular:
template<typename Tip>
void push_to_stack(stack<Tip>& A, std::istringstream&, const std::string& x) 
{
    A.push_back(std::stod(x));
}
// Для Complex:
void push_to_stack(stack<Complex>& A, std::istringstream& line, const std::string& x);

template<typename K>
void process_array()
{
    std::string input;
    std::cin.ignore(); 
    cout << "Введите строку: ";
    std::getline(std::cin, input);
    
    std::istringstream line(input); // делим на элементы 
    std::string x;

    stack<K> A;
    K a, b;
    
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
            push_to_stack(A, line, x); // перегруженная функция, ничего лучше я не придумал...
        }
    }
    cout << "Ответ: " << A.get_back() << endl; 
    // cout << A.get_back() << endl; 
    
    return;
}

int printtex();

#endif