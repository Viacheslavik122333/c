#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

int errors(double (*f)(double), double a, double b, double eps, int* error);
double division(double (*f)(double), double a, double b, double eps, int* error, int* count);
double newton(double (*f)(double), double(*derivative)(double), double x1, double eps, int* error, int* count);
double chord(double (*f)(double), double a, double b, double eps, int* error, int* count);

double f0(double x);
double f1(double x); 
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);
double f7(double x);
double f8(double x);
double f9(double x);
double f10(double x);
double f11(double x);
double f12(double x);
double f13(double x);
