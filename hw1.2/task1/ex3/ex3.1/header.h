#include"stdio.h"
#include"stdlib.h"
#include"math.h"

double f(double x);
double linear_function(double x);
double constant_function(double x);
double multi_min_function(double x);
double sharp_min_function(double x);
double negative_min_function(double x);
void find_three_points(double x0, double h, double *x1, double *x2, double *x3, double (*f)(double));
double parabolic_interpolation(double x1, double x2, double x3, double (*f)(double));
double find_minimum(double x0, double h, double eps, double (*f)(double));

// Тесты:
void test_quadratic_function(void);
void test_linear_function(void);
void test_constant_function(void);
void test_multi_min_function(void);
void test_sharp_min_function(void);
void test_negative_min_function(void);
