#include "header.h"

int main(void)
{
	double *a, *b, *x; 
	int n; // размер матрицы
	scanf("%d", &n);

	a = ArrayMatrix(n);
    b = Array(n);
    x = Array(n);
	FillArrayMatrix(a, b, n);

	// PrintArrayMatrix(a, b, n);

    // PrintSLE(a, b, n);

    if(isConvergent(n, a)){printf("The method converges! :)\n\n");} // проверка сходимости
    else{printf("The method does not converge for this SLE, try another one! :( \n"); return 0;}

    simpleIteration(n, a, b, x);

    PrintSolution(x, n);



	free(a);
    free(b);
    free(x);
	return 0;
}