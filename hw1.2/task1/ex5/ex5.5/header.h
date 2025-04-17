#include"stdio.h"
#include"stdlib.h"
#include"math.h"

int least_squares_approximation(double xv[], double yv[], int n, double *a, double *b);
int test_linear_function(FILE*fout);
int test_quadratic_function(FILE*fout);
int test_constant_function(FILE*fout);
int test_single_point(FILE*fout);
double linear_function(double x, double a, double b);