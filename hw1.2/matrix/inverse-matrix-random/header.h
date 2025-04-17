#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

double * ArrayMatrix(int m, int n);

void FillArrayMatrix(double *a, int n);

void Normalize(double *a, int m, int n);

void Gauss(double *a, int m, int n);

void PrintArrayMatrix(double *a, int m, int n);

void swap(double *matrix, int n, int a, int b);

double * InverseMatrix(double *matrix, int n);

double * multiplication (double *a, double *b, int n);

int examination (double * a, double * b, int n);
