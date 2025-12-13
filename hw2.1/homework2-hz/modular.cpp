#include <iostream>
#include <math.h>

struct modular
{
    static const int mod = 1e9 + 7;
    int res;
    modular ()
    {
        res = 0;
    }
    modular(long long t)
    {
        res = t%mod;
        if(res<0){res+=mod;}
    } 

    modular& operator=(const modular& t)
    {
        if (this != &t)
        {
            res = t.res;
        }
        return *this;
    }

    // арифметические операторы:

    //  операторы + :
    modular& operator+= (const modular& t) 
    {
        res += t.res;
        if (res >= mod) {res -= mod;}
        return *this;
    }
    modular operator+ (const modular& t) 
    {
        modular x =*this;
        x += t;
        return x;
    }
    modular& operator++() //префиксный --p
    {
        ++res;
        if (res == mod) {res = 0;}
        return *this;
    }
    
    modular operator++(int) //постфиксный p++
    {
        modular temp = *this;
        ++(*this);
        return temp;
    }


    //  операторы - :
    modular& operator-= (const modular& t) 
    {
        res -= t.res;
        if (res <= mod) {res += mod;}
        return *this;
    }
    modular operator- (const modular& t) 
    {
        modular x = *this;
        x -= t;
        return x;
    }
    modular& operator--() //префиксный
    {
        --res;
        if (res == -1) {res = mod-1;}
        return *this;
    }
    
    modular operator--(int) //постфиксный
    {
        modular x = *this;
        --(*this);
        return x;
    }

    //  операторы * и / :

    modular& operator*= (const modular &t)
    {
        long long tmp = res * t.res;
        res = tmp % mod;
        return *this;
    }
    modular operator* (const modular &t)
    {
        modular x = *this;
        x *=t;
        return x;
    }


    modular& operator/= (const modular &t)
    {
        modular x(binpow(t.res, mod-2));
        *this *= x;
        return *this;
    }

    modular operator/(const modular& t) 
    {
        modular x = *this;
        x /=t;
        return x;
    }

    long long binpow(long long a, int n) 
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

};

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

int main()
{
    modular a(1), b(3);
    std::cout << a << " " << b << std::endl;
    std::cout << "+ "<< a+b << std::endl;
    std::cout << "++a "<< ++a << std::endl;
    std::cout << "- "<< a-b << std::endl;
    std::cout << "--a "<< --a << std::endl;
    std::cout << "* "<< a*b << std::endl;
    std::cout << "/ "<< a/b << std::endl;
    return 0;
}