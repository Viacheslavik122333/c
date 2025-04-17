#include "header.h"

void FillArrayMatrix(double *matrix, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
	int i,j;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A(i, j) = rand() % 2001 - 1000; // генерация чисел от -1000 до 1000
		}
	}
#undef A
}

double * multiplication (double *a, double *b, int n)
{
#define A(i, j) a[(i)*n + (j)]
#define B(i, j) b[(i)*2*n + (j)]
#define C(i, j) c[(i)*n + (j)]
	double *c,sum=0;
	int count=0;
	c = ArrayMatrix(n, n);
	for (int i=0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			sum += A(i,j)*B(j,i+n);
		}
		C(i,count) = sum;
		count++;
		sum=0;
	}
	return c;
#undef C
#undef B
#undef A
}

int examination (double * a, double * b, int n)
{
	#define C(i, j) c[(i)*n + (j)]
	double *c;
	c = ArrayMatrix(n, n);
	c = multiplication(a, b, n);
	// printf("E:\n");
	// for(int i=0; i<n; i++) // вывод E
	// {
	// 	for(int j=0; j<n; j++){ printf("%lf ", C(i,j)); }
	// 	printf("\n");
	// }

	for(int i = 0; i<n; i++)
	{
		if(fabs(C(i,i)-1)>1e-10)
		{
			return 0;
		}
	}

	free(c);
	return 1;

#undef C
}



double * InverseMatrix(double *matrix, int n)
{
#define A(i, j) matrix[(i)*n + (j)]
#define B(i, j) b[(i)*2*n + (j)]

	double * b;
	b = ArrayMatrix(n, 2*n);

	for (int i = 0; i<n; i++) // приписываем E
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
	// printf("do:\n");
	// PrintArrayMatrix(b, m, 2*n);

	Gauss(b, n, 2*n);

	return b;

	// printf("posle:\n");
	// PrintArrayMatrix(b, m, 2*n);

#undef B
#undef A
}


void Gauss(double *matrix, int m, int n) // приводится к E
{
#define A(i, j) matrix[(i)*n + (j)]
	int col = 0, line = 0, max_line;
	double max_el, alpha, tmp;

	Normalize(matrix, m, n); // нормализуем матрицу
	
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
		// printf("находим max элемент в столбце по модулю: max_el = %lf\n", max_el);

		if(fabs(max_el) <= 1e-20) // столбец 0, обратной не существует
		{
			printf("ERROR!!! :( \n");
			return;
		}

		if(max_line != line) // ставим максимальный элемент на 1 место
		{
			swap(matrix, n, line, max_line);
		}

		// printf("ставим максимальный элемент на 1 место:\n");
		// PrintArrayMatrix(matrix, m, n);

		for(int i = line + 1; i < m; i++)
		{
			alpha = A(i, col)/A(line, col);

			for(int j=col; j<n; j++)
			{
				A(i, j) -= A(line, j) * alpha;
			}
		}
		// printf("Гаусс:\n");
		// PrintArrayMatrix(matrix, m, n);


		tmp = A(line, col);
		for(int i=0; i< n - col; i++) // делаем 1 на диагонале
		{
			A(line, col+i)/= tmp;
		}
		// printf("kakoito cikl do: line = %d, col = %d\n", line, col);
		// PrintArrayMatrix(matrix, m, n);
		
		for(int i = 1; i<line+1; i++) // обнуляем все остальные значения
		{
			alpha = -A(line-i,col);

			for(int j=col; j<n; j++)
			{
				A(line-i,j) += A(line,j) * alpha;
			}
		}
		// printf("kakoito cikl posle: line = %d, col = %d\n", line, col);
		// PrintArrayMatrix(matrix, m, n);

		col++;
		line++;
		
	}
	// printf("Reverse matrix:\n");
	// for(int i=0; i<m; i++) // вывод обратной матрицы
	// {
	// 	for(int j=n/2; j<n; j++){ printf("%lf ", A(i,j)); }
	// 	printf("\n");
	// }
#undef A
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



double * ArrayMatrix(int m, int n)
{
	double *a = (double *)malloc(m*n*sizeof(double));
	return a;
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



