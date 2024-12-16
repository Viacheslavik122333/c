#ifndef TASK
#define TASK
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Sieving_sorting_1(double a[], const size_t size);
void Sieving_sorting_2(double a[], size_t size, int (*cmp_1)(double, double));
void Sieving_sorting_3(void * a, size_t size, size_t elem_length, int (*cmp_3)(const void *, const void *));
void tabl(double res[]);
int cmp_2(double a, double b);
int cmp_3(const void * a, const void * b);
int cmp_qsort(const void *a, const void *b);
void swap(void * x, void * y, size_t size);

#endif