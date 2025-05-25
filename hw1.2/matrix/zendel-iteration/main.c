#include "header.h"

int main(void)
{
	FILE *f;
	double *a, *b, *x; 
	int n; // размер матрицы
	f = fopen("matrix.txt", "r");
	fscanf(f, "%d", &n);

	a = ArrayMatrix(n);
    b = Array(n);
    x = Array(n);
	FillArrayMatrix(a, b, n, f);

	PrintArrayMatrix(a, b, n);

    PrintSLE(a, b, n);

    if(isConvergent(n, a)){printf("The method converges! :)\n\n");} // проверка сходимости
    else{printf("The method does not converge for this SLE, try another one! :( \n"); return 0;}

    ZendelIteration(n, a, b, x);

    PrintSolution(x, n);

	free(a);
    free(b);
    free(x);
	fclose(f);
	return 0;
}