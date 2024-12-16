#include "bitradixsort.h"

void PrintArray(unsigned int *a, size_t n)
{
	size_t i;
	printf("[");
        for(i = 0; i < n; ++i) printf("%d ", a[i]);
	printf("]\n");
}

bool TestSort(int n, unsigned int *a)
{
	int i;
	for (i=1; i<n; i++) {
		if (a[i-1] < a[i]) return false;
	}
	return true;
}

int CompareVoid(const void *a, const void *b)
{
	const unsigned int *pa = (const unsigned int *)a;
	const unsigned int *pb = (const unsigned int *)b;
	return (*pa<*pb) ? -1 : (*pa>*pb) ? 1 : 0;
}

bool TestBit(unsigned int n, int k)
{
	return n & (1<<k);
}


void BitRadixSort (unsigned int *a, int n, unsigned int *b)
{
	int i, k, j0, j1, n0, n1;
    int size = sizeof(int)*8;
	for (k=0; k<size; k++) {
		n0 = n1 = 0;
		for (i=0; i<n; i++) {
			if (TestBit(a[i],k)) { n1++; } else { n0++; }
		}
		j0 = 0;
		j1 = n0;
		for (i=0; i<n; i++) {
			if (TestBit(a[i],k)) {b[j1++] = a[i]; } else {b[j0++] = a[i]; }
		}

		for (i=0; i<n; i++) { a[i] = b[i]; }
	}
}

