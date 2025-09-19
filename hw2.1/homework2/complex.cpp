#include <iostream>


struct Complex
{
    double re;
    double im;
    Complex ()
    {
        re = 0;
        im = 0;
    }
    Complex (double x)
    {
        re = x;
        im = 0;
    }
    Complex (double x, double y)
    {
        re = x;
        im = y;
    }
    Complex conjugation() const
    {
        return Complex(re, -im);
    }

    Complex& operator=(const Complex& t)
    {
        if (this != &t)
        {
            re = t.re;
            im = t.im;
        }
        return *this;
    }

    // арифметические операторы:
    Complex& operator+= (const Complex& t)
    {
        re += t.re;
        im += t.im;
        return *this;
    }

    Complex operator+ (const Complex& t)
    {
        Complex x = *this;
        x += t;
        return x;
    }

    Complex& operator-= (const Complex& t)
    {
        re -= t.re;
        im -= t.im;
        return *this;
    }

    Complex operator- (const Complex& t)
    {
        Complex x = *this;
        x -= t;
        return x;
    }


    Complex operator* (const Complex &t)
    {
        Complex x(re,im);
        x.re = re*t.re - im*t.im;
        x.im = im*t.re + re*t.im;
        return x;
    }

    Complex operator/ (Complex& t)
    {
        Complex x(re,im);
        double tmp = t.re*t.re + t.im*t.im;
        x = x * t.conjugation();
        x.re = x.re/tmp;
        x.im = x.im/tmp;
        return x;
    }
    
};

std::ostream& operator<< (std::ostream& out, const Complex &x)
{
    out << "(" << x.re << ", " << x.im << ")"<<" ";
    return out;
}
std::ostream& operator>> (std::ostream& out, const Complex &x)
{
    out >> x;
    return out;
}


int main()
{
    Complex a(1,2), b(3,4);
    std::cout << a;
    std::cout << a+b;
    std::cout << a-b;
    std::cout << a*b;
    std::cout << a/b;
    return 0;
}



