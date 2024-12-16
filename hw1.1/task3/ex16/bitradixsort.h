#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void PrintArray(unsigned int *a, size_t n); // выводит массив

bool TestSort(int n, unsigned int *a); // проверка сортировки 

int CompareVoid(const void *a, const void *b); // функуия сравнение типа void

bool TestBit(unsigned int a, int k); 

void BitRadixSort (unsigned int *a, int n, unsigned int *b); // битовая сортировка
