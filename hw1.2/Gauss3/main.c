#include "header.h"

int main(void)
{
	FILE *f;
	double *a;
	int m, n;
	f = fopen("matrix.txt", "r");
	fscanf(f, "%d %d", &m, &n);

	a = ArrayMatrix(m, n);
	FillArrayMatrix(a, m, n, f);

	printf("Original matrix:\n");
	PrintArrayMatrix(a, m, n);

	Gauss(a, m, n);
	printf("\nModified matrix:\n");
	PrintArrayMatrix(a, m, n);

	free(a);
	fclose(f);
	return 0;
}