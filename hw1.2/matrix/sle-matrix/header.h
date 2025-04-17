#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double * ArrayMatrix(int m, int n);

void FillArrayMatrix(double *a, int m, int n, FILE *f);

void PrintSLE(double *a, int m, int n);

int SolutionSLE(double * a, int m, int n, double * Solution);

void PrintSolution(double * Solution, int m);

void Normalize(double *a, int m, int n);

void Gauss(double *a, int m, int n, double * Solution);

void PrintArrayMatrix(double *a, int m, int n);

void swap(double *matrix, int n, int a, int b);

