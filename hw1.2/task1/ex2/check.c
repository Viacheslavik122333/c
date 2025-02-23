#include "header.h"

double f1(double x)
{
    return (3 * x * x);
}
double f2(double x)
{
    return (3 * x * x);
}
double f3(double x)
{
    return (3 * x * x);
}
double f4(double x)
{
    return (3 * x * x);
}
double f5(double x)
{
    return (3 * x * x);
}
double f6(double x)
{
    return (1/x);
}
double f7(double x)
{
    return (1/x);
}
double f8(double x)
{
    return (x * cos(x));
}
double f9(double x)
{
    return (x * cos(x));
}
double f10(double x)
{
    return (1/(pow(cos(x), 4)));
}


void auxiliary_function(double eps[], double answer[], const char *Errors[], const char *Name_functions[], double a[], double b[])
{
    Errors[0] = "Ошибка...";
    Errors[1] = "Некорректный отрезок";
    Errors[2] = "Некорректный ввод eps";
    Errors[3] = "Слишком много итериций";

    Name_functions[0] = "-----rectangle-----";
    Name_functions[1] = "-----trapezoid-----";
    Name_functions[2] = "------Simpson------";
    Name_functions[3] = "-------Gauss-------";

    eps[0] = 1e-6; eps[1] = 1e-9; eps[2] = 1e-6; eps[3] = -1e-6; eps[4] = 1e-6;
    eps[5] = 1e-6; eps[6] = 1e-12; eps[7] = 1e-5; eps[8] = 1e-13; eps[9] = 1e-6;

    answer[0] = 8; answer[1] = 8; answer[2] = 8; answer[3] = 8; answer[4] = 0; answer[5] = 3*log(2); 
    answer[6] = 3*log(2); answer[7] = 9*sin(9)+cos(9)-1; answer[8] = 20*sin(20)+cos(20)-sin(1)-cos(1); 
    answer[9] = (pow(tan(1), 3))/3 + tan(1);

    a[0] = 0; a[1] = 0; a[2] = 5; a[3] = 0; a[4] = 6; a[5] = 1; a[6] = 1; a[7] = 0; a[8] = 1; a[9] = 0;
    b[0] = 2; b[1] = 2; b[2] = 2; b[3] = 2; b[4] = 6; b[5] = 8; b[6] = 8; b[7] = 9; b[8] = 20; b[9] = 1;
}

double FUN(int i, double (*func)(double), double a, double b, double eps, int *Tmp)
{
    double res;
    switch (i)
    {
        case 0:
            res = rectangle(func, a, b, eps, Tmp);
            break;

        case 1:
            res = trapezoid(func, a, b, eps, Tmp);
            break;

        case 2:
            res = Simpson(func, a, b, eps, Tmp);
            break;

        case 3:
            res = Gauss(func, a, b, eps, Tmp);
            break;
    }
    return res;
}