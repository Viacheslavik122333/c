#include "headerE.h"

Complex::Complex ()
{
    re = 0;
    im = 0;
}
Complex::Complex (double x)
{
    re = x;
    im = 0;
}
Complex::Complex (double x, double y)
{
    re = x;
    im = y;
}
Complex::Complex(const Complex& t)
{
    re=t.re;
    im=t.im;
}
Complex Complex::conjugation() const
{
    return Complex(re, -im);
}
Complex& Complex::operator=(const Complex& t)
{
    if (this != &t)
    {
        re = t.re;
        im = t.im;
    }
    return *this;
}
// арифметические операторы:
Complex& Complex::operator+= (const Complex& t)
{
    re += t.re;
    im += t.im;
    return *this;
}
Complex Complex::operator+ (const Complex& t)
{
    Complex x = *this;
    x += t;
    return x;
}
Complex& Complex::operator-= (const Complex& t)
{
    re -= t.re;
    im -= t.im;
    return *this;
}
Complex Complex::operator- (const Complex& t)
{
    Complex x = *this;
    x -= t;
    return x;
}
Complex Complex::operator* (const Complex &t)
{
    Complex x(re,im);
    x.re = re*t.re - im*t.im;
    x.im = im*t.re + re*t.im;
    return x;
}
Complex Complex::operator/ (Complex& t)
{
    Complex x(re,im);
    double tmp = t.re*t.re + t.im*t.im;
    x = x * t.conjugation();
    x.re = x.re/tmp;
    x.im = x.im/tmp;
    return x;
}

std::ostream& operator<< (std::ostream& out, const Complex &x)
{
    out << "(" << x.re << ", " << x.im << ")"<<" ";
    return out;
}
std::istream& operator>> (std::istream& in, Complex &x)
{
    in >> x.re >> x.im;
    return in;
}


modular::modular ()
{
    res = 0;
}
modular::modular(long long t)
{
    res = t%mod;
    if(res<0){res+=mod;}
}
modular::modular(const modular& t)
{
    res = t.res;
} 
modular& modular::operator=(const modular& t)
{
    if (this != &t)
    {
        res = t.res;
    }
    return *this;
}
// арифметические операторы:
//  операторы + :
modular& modular::operator+= (const modular& t) 
{
    res += t.res;
    if (res >= mod) {res -= mod;}
    return *this;
}
modular modular::operator+ (const modular& t) 
{
    modular x =*this;
    x += t;
    return x;
}
modular& modular::operator++() //префиксный --p
{
    ++res;
    if (res == mod) {res = 0;}
    return *this;
}
modular modular::operator++(int) //постфиксный p++
{
    modular temp = *this;
    ++(*this);
    return temp;
}
//  операторы - :
modular& modular::operator-= (const modular& t) 
{
    res -= t.res;
    if (res <= mod) {res += mod;}
    return *this;
}
modular modular::operator- (const modular& t) 
{
    modular x = *this;
    x -= t;
    return x;
}
modular& modular::operator--() //префиксный
{
    --res;
    if (res == -1) {res = mod-1;}
    return *this;
}
modular modular::operator--(int) //постфиксный
{
    modular x = *this;
    --(*this);
    return x;
}
//  операторы * и / :
modular& modular::operator*= (const modular &t)
{
    long long tmp = res * t.res;
    res = tmp % mod;
    return *this;
}
modular modular::operator* (const modular &t)
{
    modular x = *this;
    x *=t;
    return x;
}
modular& modular::operator/= (const modular &t)
{
    modular x(binpow(t.res, mod-2));
    *this *= x;
    return *this;
}
modular modular::operator/(const modular& t) 
{
    modular x = *this;
    x /=t;
    return x;
}
long long modular::binpow(long long a, int n) 
{
    long long  tmp = 1;
    while (n != 0) 
    {
        if (n & 1)
        {
            tmp = tmp * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return tmp;
}

std::ostream& operator<< (std::ostream& out, const modular &x)
{
    out << x.res;
    return out;
}
std::istream& operator >> (std::istream& in, modular &x)
{
    in >> x.res;
    return in;
}

void push_to_stack(stack<Complex>& A, std::istringstream& line, const std::string& x)
{
    double re = std::stod(x);
    std::string _im;
    if (line >> _im) 
    {
        double im = std::stod(_im);
        Complex tmp(re, im);
        A.push_back(tmp);
    }
    else 
    {
        cout << "Не хватает мнимой части";
        exit (-1);
    }
    
}

int printtex()
{
    int tmp;
    printf("Выберите один из 4 вариантов: \n");
    printf("1 int \n");
    printf("2 double \n");
    printf("3 complex \n");
    printf("4 modular \n");
    printf("Введите число: ");
    cin >> tmp;
    return tmp;
}

