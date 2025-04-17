#include "header.h"

bool isConvergent(int n, double * a) // проверка на сходимость метода ( |a_{ii}|> |\sum_{i \neq j} a_{ij}| )
{
#define A(i, j) a[(i)*n + (j)]
    for (int i = 0; i < n; i++) 
    {
        double sum = 0.0;
        for (int j = 0; j < n; j++) 
        {
            if (i != j) sum += fabs(A(i,j));
        }
        if (fabs(A(i,i)) < sum) return false;
    }
    return true;
#undef A
}

void simpleIteration(int n, double * a, double * b, double * x)
{
#define A(i, j) a[(i)*n + (j)]
    double x_new[n];
    int iterations = 0;
    double difference=1, tmp;
    int MAX_ITERATIONS = 100;
    double eps = 1e-10; // заданная точность

    for(int i = 0; i < n; i++) {x[i] = 0;} // заполним изначально решения нулями

    while (iterations < MAX_ITERATIONS && difference > eps)
    {
        difference = 0;
        
        for (int i = 0; i < n; i++) 
        {
            x_new[i] = b[i];

            for (int j = 0; j < n; j++) 
            {
                if (i != j) 
                {
                    x_new[i] -= A(i,j) * x[j];
                }
            }

            x_new[i] /= A(i,i);
            
            tmp = fabs(x_new[i] - x[i]);

            if (tmp > difference) difference = tmp;
        }
        
        for (int i = 0; i < n; i++) x[i] = x_new[i];
        
        iterations++;
    }

    printf("iterations = %d\n\n", iterations);
#undef A
}


double * ArrayMatrix(int n)
{
	double *a = (double *)malloc(n*n*sizeof(double));
	return a;
}
double * Array(int n)
{
	double *a = (double *)malloc(n*sizeof(double));
	return a;
}


void FillArrayMatrix(double *a, double *b, int n, FILE *f)
{
#define A(i, j) a[(i)*n + (j)]
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(f, "%lf", &A(i, j));
		}
        fscanf(f, "%lf", &b[i]);
	}
#undef A
}


void PrintSolution(double * x, int n)
{
    printf("Solution:\n");
	for(int i = 0; i<n; i++)
	{
		printf("x_%d = %lf, ", i+1, x[i]);
	}
	printf("\n");
}

void PrintSLE(double *a, double * b, int n)
{
#define A(i, j) a[(i)*n + (j)]
    printf("SLE:\n");
	for(int i=0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
            if(A(i,j)>1e-15 && j!=0){printf("+ ");}
			printf("%lfx_%d ", A(i,j), j+1);
            
		}
		printf("= %lf\n", b[i]);
	}
	printf("\n");
#undef A
}

void PrintArrayMatrix(double *a, double *b, int n)
{
#define A(i, j) a[(i)*n + (j)]
	int i,j;
    printf("Matrix:\n");
	for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
		{
			printf("%lf ", A(i,j));
		}
        printf(" |  %lf\n", b[i]);
	}
	printf("\n");
#undef A
}