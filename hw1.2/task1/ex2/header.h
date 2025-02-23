#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


double rectangle (double (*func)(double), double a, double b, double eps, int *Tmp);  // Метод прямоугольникоми
double trapezoid (double (*func)(double), double a, double b, double eps, int *Tmp);  // Метод трапециями
double Simpson (double (*func)(double), double a, double b, double eps, int *Tmp);    // Метод Симсона
double Gauss (double (*func)(double), double a, double b, double eps, int *Tmp);      // Метод Гаусса

int errors(double a, double b, double eps, int *Tmp); // Ошибки 

double FUN (int j, double (*func)(double), double a, double b, double eps, int *Tmp); // Выбор метода
void auxiliary_function(double eps[], double answer[], const char *Errors[], const char *Name_functions[], double a[], double b[]); // Функция заполняет массивы: eps, ответы, ошибки, названия функций, данные отрезка [a, b]

double f1(double x);  // f(x) = 3x^2
double f2(double x);  // f(x) = 3x^2
double f3(double x);  // f(x) = 3x^2
double f4(double x);  // f(x) = 3x^2
double f5(double x);  // f(x) = 3x^2
double f6(double x);  // f(x) = 1/x
double f7(double x);  // f(x) = 1/x
double f8(double x);  // f(x) = x * cos(x)
double f9(double x);  // f(x) = x * cos(x)
double f10(double x); // f(x) = 1/(cos(x)^4)