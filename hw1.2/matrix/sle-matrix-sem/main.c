#include "header.h"

// в файле matrix.txt сначала размеры матрицы m-строк, n-столбцов (без столбца решений)
// потом сама матрица, в которой n+1 столбец, так как n+1 - это столбец решения

int main(void)
{
	double *a;
	int n;
	double * Solution;
	scanf("%d", &n);
	Solution = (double *)malloc( (n+1) * sizeof(double));
	a = ArrayMatrix(n, n+1);
	FillArrayMatrix(a, n, n);

	printf("System of linear equations:\n");
	PrintSLE(a, n, n+1);

	if(SolutionSLE(a, n, n+1, Solution))
	{
		PrintSolution(Solution, n);
	}

	free(a);
	return 0;
}
