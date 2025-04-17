#include"stdio.h"
#include"stdlib.h"
#include"math.h"

double hermite_interpolation(double x, double x_values[], double y_values[], double dy_values[], int n); 
int test_linear_function(FILE*fout);
int test_quadratic_function(FILE*fout);
int test_constant_function(FILE*fout);
int test_multiple_points(FILE*fout);
int test_single_point(FILE*fout);