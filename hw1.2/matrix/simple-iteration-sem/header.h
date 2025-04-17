#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


bool isConvergent(int n, double * a);
void simpleIteration(int n, double * a, double * b, double * x);
double * ArrayMatrix(int n);
double * Array(int n);
void PrintArrayMatrix(double *a, double *b, int n);
void PrintSLE(double *a, double * b, int n);
void PrintSolution(double * x, int n);
void FillArrayMatrix(double *a, double *b, int n);
double norma(double *a, int n);