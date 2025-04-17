#include "header.h"

double Determinant(double *a, int n)
{
#define A(i, j) a[(i)*n + (j)]
	double res=1, max_el;
	int countswap;

	max_el = Normalize(a, n, n);

	countswap = Gauss(a, n, n);

	for (int i = 0; i<n; i++)
	{
		res*=A(i,i) * max_el;
	}
	
	return res*(pow(-1,countswap));
#undef A
}


int Gauss(double *matrix, int m, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
	int col = 0, line = 0, max_line, countswap=0;
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
			countswap++;
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
	return countswap;
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

double Normalize(double *matrix, int m, int n)
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
	return max_el;
}



double * ArrayMatrix(int n)
{
	double *a = (double *)malloc(n*n*sizeof(double));
	return a;
}

void FillArrayMatrix(double *matrix, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j) A(i,j) = 2;
			else if(i==j+1 || i == j-1) A(i,j) = -1;
			else A(i,j) = 0;
		}
	}
#undef A
}

void PrintArrayMatrix(double *matrix,int n)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){printf("%lf ", A(i,j));}
		printf("\n");
	}
	printf("\n");
#undef A
}


