#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double * ArrayMatrix(int m, int n);

void FillArrayMatrix(double *a, int m, int n, FILE *f);

void Normalize(double *a, int m, int n);

void Gauss(double *a, int m, int n);

void PrintArrayMatrix(double *a, int m, int n);

void swap(double *matrix, int n, int a, int b);

void InverseMatrix(double *matrix, int m, int n);
