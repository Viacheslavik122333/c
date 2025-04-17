#include "header.h"

// в файле matrix.txt сначала размеры матрицы m-строк, n-столбцов (без столбца решений)
// потом сама матрица, в которой n+1 столбец, так как n+1 - это столбец решения

int main(void)
{
	FILE *f;
	double *a;
	int m, n;
	double * Solution;
	f = fopen("matrix.txt", "r");
	fscanf(f, "%d %d", &m, &n);
	Solution = (double *)malloc( (n+1) * sizeof(double));

	a = ArrayMatrix(m, n+1);
	FillArrayMatrix(a, m, n+1, f);

	printf("System of linear equations:\n");
	PrintSLE(a, m, n+1);

	if(SolutionSLE(a, m, n+1, Solution))
	{
		PrintSolution(Solution, n);
	}

	free(a);
	fclose(f);
	return 0;
}
