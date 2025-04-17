#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

double * ArrayMatrix(int n);

void FillArrayMatrix(double *a, int n);

double Normalize(double *a, int m, int n);

int Gauss(double *a, int m, int n);

void PrintArrayMatrix(double *a, int n);

void swap(double *matrix, int m, int n, int a, int b);

double Determinant(double *matrix, int n);
