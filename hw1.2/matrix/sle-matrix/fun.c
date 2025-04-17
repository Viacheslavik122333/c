#include "header.h"

int SolutionSLE(double * a, int m, int n, double * Solution)
{
#define A(i, j) a[(i)*n + (j)]
	double sum=0;
	int k=m-1;
	int index=0;
	Gauss(a, m, n, Solution);
	printf("Matrix after Gaussian algorithm:\n");
	PrintArrayMatrix(a, m, n);
	for(int i = m; i<n-1; i++) // крайние (справа) свободные переменные будут принимать значения 1
	{
		Solution[i]=1;
	}

	while(k>=0)
	{
		for(int p = 0; p<n; p++)  // ищем индекс первого не нулевого элемента в строке (лидер)
		{
			if(fabs(A(k,p))<1e-15){continue;}
			if(p==n-1 || fabs(A(k,n-1))<1e-15){printf("ERROR\n"); return 0;} // система несовместна :(
			index=p;
			break;
		}
		for(int i=index+1; i<n-1; i++)
		{
			sum +=A(k,i)*Solution[i];
		}
		Solution[index] = (A(k,n-1) - sum)/A(k,index);
		sum=index=0;
		k--;
	}
	return 1;

#undef A
}

void Gauss(double *matrix, int m, int n, double * Solution)
{
#define A(i, j) matrix[(i)*n + (j)]
	int col = 0, line = 0, max_line;
	double max_el, alpha;

	Normalize(matrix, m, n);

	while(col < n && line < m)
	{
		max_el = A(line, col);
		max_line = line;
		for(int i=line+1; i<m; i++) // находим max элемент в столбце по модулю
		{
			if(fabs(max_el) < fabs(A(i, col)))
			{
				max_el = A(i, col); 
				max_line = i;
			}
		}

		if(fabs(max_el) <= 1e-20) // скипаем столбец (странно) все 0
		{
			Solution[col] = 1; // свободные переменные будут принимать значения 1 (не крайние)
			col++;
			continue;
		}

		if(max_line != line) // ставим максимальный элемент на 1 место
		{
			swap(matrix, n, line, max_line);
		}

		for(int i = line + 1; i < m; i++)
		{
			alpha = A(i, col)/A(line, col);

			for(int j=col; j<n; j++)
			{
				A(i, j) -= A(line, j) * alpha;
			}
		}
		col++;
		line++;
	}
#undef A
}


double * ArrayMatrix(int m, int n)
{
	double *a = (double *)malloc(m*n*sizeof(double));
	return a;
}

void FillArrayMatrix(double *matrix, int m, int n, FILE *f)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(f, "%lf", &A(i, j));
		}
	}
#undef A
}

void PrintSLE(double *a, int m, int n)
{
#define A(i, j) a[(i)*n + (j)]
	for(int i=0; i<m; i++)
	{
		for(int j = 0; j<n-1; j++)
		{
			printf("%lfx_%d ", A(i,j), j+1);
			if(j!=n-2){printf("+ ");}
			else{printf("= ");}
		}
		printf("%lf\n", A(i, n-1));
	}
	printf("\n");
#undef A
}

void PrintSolution(double * Solution, int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("x_%d = %lf, ", i+1, Solution[i]);
	}
	printf("\n");
}


void swap(double *matrix, int n, int a, int b)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i;
	double tmp;
	for(i=0; i<n; i++)
	{
		tmp = A(a, i);
		A(a, i) = A(b, i);
		A(b, i) = tmp;
	}
#undef A
}

void Normalize(double *matrix, int m, int n)
{
	int i;
	double max_el = 0, delta = 1e-15;
	for (i=0;i<m*n;i++) // ищем максимальный элемент по модулю
	{
		if(fabs(matrix[i]) > fabs(max_el))
		{
			max_el = matrix[i];
		}
	}
	for (i=0;i<m*n;i++) // делим все элементы на максимальный
	{
		matrix[i] /= max_el;
		if(fabs(matrix[i]) < delta * (m+n)/2)
		{
			matrix[i] = 0;
		}
	}
}

void PrintArrayMatrix(double *matrix, int m, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		{
			if(j == n-1){printf(" | ");}
			printf("%lf ", A(i,j));
			
		}
		printf("\n");
	}
	printf("\n");
#undef A
}


