#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int SortMatrix(int **arr, int m, int n, int M, int N);
int** mallocMatrix(int m, int n);
void freeMatrix(int **arr, int m);
void PrintMatrix(int **arr, int m, int n);
void fillMatrix(int **arr, int m, int n, FILE *f);
void DeleteMatrix(int **arr, int k, int m, int n);
