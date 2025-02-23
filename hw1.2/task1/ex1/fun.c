#include "header.h"

double division(double (*f)(double), double a, double b, double eps, int* error, int* count)
{
    double center  = (a + b) / 2;
    int cnt = 0;
    double f_a=f(a);
    double f_c=f(center);
    double flag = 0;
    *error = 0;
    *count = 0;

    if(errors(f, a, b, eps, error) != 1)  // проверка ошибок
    {
        return -1;
    }

    while((b - a) > eps && fabs(b-flag) > 1e-16) 
    {
        cnt++;
        center = (a + b) / 2;
        f_c = f(center);

        if (fabs(f_c) < eps) 
        {
            *count = cnt;
            return center;
        }

        if (f_a * f_c < 0)
        {
            flag = b;
            b = center;
        } 
        else 
        {
            flag = a;
            a = center;
            f_a = f_c;
        }
    }
    *count = cnt;
    return (a + b) / 2;
    
}

double newton(double (*f)(double), double(*derivative)(double), double x1, double eps, int* error, int* count)
{
    int cnt = 0;
    double x2;
    double tmp;
    double flag = x1;
    *error = 0;
    *count = 0;
    if(fabs(derivative(x1))>1e-16) 
        x2 = x1 - f(x1) / derivative(x1);
    else 
    {
        *error = 4;    // деление на 0
        return -1;
    }

    if(eps <= 0) 
    {
        *error = 2; // Некорректный ввод eps
        return -1;
    }

    while (fabs(flag-x2)>eps) 
    {

        cnt++;
        tmp = derivative(x1);
        if (fabs(tmp) < 1e-16)
        {
            *error = 4;    // деление на 0
            *count = cnt;
            return -1;
        }
        x2 = x1 - f(x1) / tmp;

        if (fabs(x2 - x1) < eps) 
        {
            *count = cnt;
            error = 0;
            return x2;
        }

        flag = x1;
        x1 = x2;
    }
    *count = cnt;
    return x2;
}

double chord(double (*f)(double), double a, double b, double eps, int* error, int* count)
{
    double c;
	int cnt = 0;
    double f_a = f(a);
    double f_b = f(b);
    *error = 0;

    if (fabs(f_a - f_b) < eps)
    {
        if(fabs(f_a) < eps) {return a;}
        *error = 3; // Корень вне отрезка
        return -1;
    }

    if( errors(f, a, b, eps, error) != 1) // проверка ошибок
    {
        return -1;
    }

	while (1) {
        cnt++;
        f_b = f(b);
        f_a = f(a);

        c = b - f_b * (b - a) / (f_b - f_a);

        if (fabs(c - b) < eps) 
        {
            *count = cnt;
            return c;
        }

        a = b;
        b = c;

        if (fabs(f_b - f_a) < eps) 
        {
            *error = 4;  // деление на 0
            *count = cnt;
            return -1;
        }
    }
    *count = cnt;
    return c;
}

int errors(double (*f)(double), double a, double b, double eps, int* error)
{
    if((a-b)>eps) 
    {
        *error = 1; // Некорректный отрезок
        return -1;
    }

    if(eps <= 0) 
    {
        *error = 2; // Некорректный ввод eps
        return -1;
    }

    if((b-a)<eps) 
    {
        if (fabs(f(a)) < eps) 
        {
            *error = 0; // Найден корень
            return 1;
        } else {
            *error = 3; // Корень вне отрезка
            return -1;
        }
    }

    if(f(a) * f(b) > 0)
    {
        *error = 3; // Корень вне отрезка 
        return -1;
    }

    return 1;
}