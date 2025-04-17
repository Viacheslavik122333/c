#include "header.h"

int main(void)
{
	FILE *f;
	double *a;
	int m, n;
	double det, max_el;
	int countswap;
	int rk;

	f = fopen("matrix.txt", "r");
	fscanf(f, "%d %d", &m, &n);
	a = ArrayMatrix(m, n);
	FillArrayMatrix(a, m, n, f);

	InverseMatrix(a, m, n);

	printf("Исходная:\n");
	PrintArrayMatrix(a, m, n);
	max_el = Normalize(a, m, n);

	printf("После нормы:\n");
	PrintArrayMatrix(a, m, n);
	countswap = Gauss(a, m, n);

	printf("Итоговая:\n");
	PrintArrayMatrix(a, m, n);

	rk = RankMatrix(a, m, n);
	printf("rk = %d\n", rk);

	det =  Determinant(a, m, n, max_el, countswap);
	printf("det = %lf\n", det);



	free(a);
	fclose(f);
	return 0;
}