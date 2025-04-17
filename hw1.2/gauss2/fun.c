#include "header.h"

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
	for (i=0;i<m*n;i++)
	{
		if(fabs(matrix[i]) > fabs(max_el)){max_el = matrix[i];}
	}
	for (i=0;i<m*n;i++)
	{
		matrix[i] /= max_el;
		if(fabs(matrix[i]) < delta * (m+n)/2){matrix[i] = 0;}
	}
	return max_el;
}

int Gauss(double *matrix, int m, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
        int i,j, col = 0, row = 0, max_row;
		double max_el, alpha;
		int countswap=0;
		while(col < n && row < m)
		{
			max_el = A(row, col);
			max_row = row;
			for(i=row+1; i<m; i++)
			{
				if(fabs(max_el) < fabs(A(i, col)))
				{
					max_el = A(i, col); 
					max_row = i;
				}
			}
			if(fabs(max_el) <= 1e-20)
			{
				col++; continue;
			}
			if(max_row != row)
			{
				swap(matrix, m, n, row, max_row);
				countswap++;
			}
			for(i = row + 1; i < m; i++)
			{
				alpha = A(i, col)/A(row, col);
				for(j=col; j<n; j++)
				{
					A(i, j) -= A(row, j) * alpha;
				}
			}
			col++;
			row++;
		}
		return countswap;
#undef A
}

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

double Determinant(double *matrix, int m, int n, double max_el, int countswap)
{
#define A(i, j) matrix[(i)*n + (j)]
	double res=1;
	if(n!=m){printf("incorrect data\n"); return 0;}

	for (int i = 0; i<n; i++)
	{
		res*=A(i,i) * max_el;
	}
	return res*(-1*countswap);
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

void InverseMatrix(double *matrix, int m, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
#define B(i, j) b[(i)*2*n + (j)]
	int col = 0, row = 0, max_row;
	double max_el, alpha, Max_el;
	double * b;
	if(n!=m){printf("incorrect data\n"); return;}
	b = ArrayMatrix(n, 2*n);
	for (int i = 0; i<m; i++) // приписываем E
	{
		for(int j = 0; j<2*n; j++)
		{
			if(j>=n)
			{
				if(j==n+i){B(i,j) = 1;}
				else{B(i,j) = 0;}
			}
			else
			{
				B(i,j) = A(i,j);
			}	
		}
	}
	PrintArrayMatrix(b, m, 2*n);

	Max_el = Normalize(b, m, 2*n);
	if(Max_el == 1){printf("хуй");}

	PrintArrayMatrix(b, m, 2*n);

	while(col < 2*n && row < m) // реализация приведения исходной матрицы к E
	{
		max_el = B(row, col);
		max_row = row;
		for(int i=row+1; i<m; i++)
		{
			if(fabs(max_el) < fabs(B(i, col)))
			{
				max_el = B(i, col); 
				max_row = i;
			}
		}
		if(fabs(max_el) <= 1e-20)
		{
			col++; 
			continue;
		}
		if(max_row != row)
		{
			swap(b, m, 2*n, row, max_row);
		}
		for(int i = row + 1; i < m; i++)
		{
			alpha = B(i, col)/B(row, col);
			for(int j=col; j<n; j++)
			{
				B(i, j) -= B(row, j) * alpha;
			}
		}
		col++;
		row++;
	}
	PrintArrayMatrix(b, m, 2*n);

#undef B
#undef A
}

