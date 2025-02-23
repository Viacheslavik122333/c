#include "header.h"

// f(x) = x^2 - 2, x=sqrt(2)
double f0(double x) // test1
{
    return x * x - 2;
}

// f(x) = x^2 - 2, x=sqrt(2)
double f1(double x) // test2
{
    return x * x - 2;
}
// f(x) = x^2 - 2, x=sqrt(2)
double f2(double x) // test3
{
    return x * x - 2;
}

// f(x) = x^2 - 2, x=sqrt(2)
double f3(double x) // test4
{
    return x * x - 2;
}

// f(x) = x^2-5x-6, x = 6
double f4(double x) // test5
{
    return x*x - 5 * x - 6;
}

// f(x) = x^2-5x-6, x = 6
double f5(double x) // test6
{
    return x*x - 5 * x - 6;
}

// f(x) = x^2 - 2, x=sqrt(2)
double f6(double x) // test7
{
    return x * x - 2;
}

// f(x) = x^2 - 2, x=sqrt(2)
double f7(double x) // test8
{
    return x * x - 2;
}

// f(x) = x^2 - 2, x=sqrt(2)
double f8(double x) // test9
{
    return x * x - 2;
}

// f(x) = x^2 - 2, x=sqrt(2)
double f9(double x) // test10
{
    return x * x - 2;
}

// f(x) = e^(x)-1, x = 0
double f10(double x) // test11
{
    return exp(x) - 1;
}

double f11(double x) 
{
    return 2*x;
}
double f12(double x) 
{
    return x;
}
double f13(double x)
{
    if(fabs(x)<1e-6) return 1;
    return x/x;
}
