#include "header.h"

int RankMatrix(double * matrix, int m, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
	int res=0;
	for (int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(fabs( A(i, j) )>1e-15)
			{
				res++;
				break;
			}
		}
	}
	return res;
#undef A
}

void Gauss(double *matrix, int m, int n)
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
			col++; 
			continue;
		}

		if(max_line != line) // ставим максимальный элемент на 1 место
		{
			swap(matrix, m, n, line, max_line);
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

void swap(double *matrix, int m, int n, int a, int b)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i;
	double tmp;
	for(i=0; i<m; i++)
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

void PrintArrayMatrix(double *matrix, int m, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){printf("%lf ", A(i,j));}
		printf("\n");
	}
	printf("\n");
#undef A
}


