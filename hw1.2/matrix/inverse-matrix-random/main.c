#include "header.h"
#include "time.h"

int main(void)
{
	double *a, *b;
	int n;
	double t;

	scanf("%d", &n);
	a = ArrayMatrix(n, n);
	FillArrayMatrix(a, n);

	// printf("Original matrix:\n");
	// PrintArrayMatrix(a, n, n);
	t = clock();
	b = InverseMatrix(a, n);
	t = (clock() - t) / CLOCKS_PER_SEC;

	if(examination (a, b, n))
	{
		printf("The matrix of size %d*%d was successfully obtained for %.2f seconds! :)", n,n, t);
	}
	else{printf("The %d*%d matrix did not work! :(", n, n);}

	free(a);
	return 0;
}