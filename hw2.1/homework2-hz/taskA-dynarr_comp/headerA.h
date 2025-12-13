#ifndef taskA
#define taskA

#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

template <typename T>
struct dynarr
{
    T *arr;
    int mx_sz;
    int cur_sz;

    dynarr()
    {
        arr = new T[4];
        mx_sz = 4;
        cur_sz = 0;
    }

    ~dynarr()
    {
        delete[] arr;
    }

    int push_back(T x)
    {
        if(cur_sz < mx_sz)
        {
            arr[cur_sz++]=x;
            return 0;
        }
        T*narr = new T[2 * mx_sz];
        if(narr == nullptr)
        {
            // printf("не выделилась память (");
            return -1;
        }
        for(int i=0; i<mx_sz; ++i)
        {
            narr[i]=arr[i];
        }
        mx_sz*=2;
        delete(arr);
        arr = narr;
        arr[cur_sz++] = x;
        return 0;
    }

    int pop_back ()
    {
        if(cur_sz == 0)
        {
            // printf("cur_sz == 0, не делай так!");
            return -1;
        }
        --cur_sz;
        return 0;
    }

    T operator [] (int i) const
    {
        if(i<0 || i>=cur_sz)
        {
            printf("x<0 || x>cur_sz, не делай так! i = %d\n", i);
            exit (1);
        }
        return arr[i];
    }
};

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

template<typename K>
void process_array() 
{
    int n, t, j;
    dynarr<K> arr;
    K x;

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
            fout << arr.push_back(x) << endl;
            break;
        case 1:
            fout << arr.pop_back() << endl;
            break;

        case 2:
            fin >> j;
            fout << arr[j] << endl;
            break;
        }
    }

    fin.close();
    fout.close();

}

int printtex();

#endif
