#include "header.h"

int main(void)
{
	double *a;
	int n;
	double t, res;
	scanf("%d", &n);
	a = ArrayMatrix(n);
	FillArrayMatrix(a, n);

	// printf("Original matrix:\n");
	// PrintArrayMatrix(a, n);
	t = clock();
	res = Determinant(a, n);
	t = (clock() - t) / CLOCKS_PER_SEC;
	printf("det = %d+1, received det %.2lf, time: %.3lf sec\n", n, res, t);

	free(a);
	return 0;
}