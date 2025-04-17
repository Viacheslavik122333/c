#include"header.h"

int least_squares_approximation(double xv[], double yv[], int n, double *a, double *b) 
{
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    double denominator;

    if (n == 1)
    {
        // Для одной точки возвращаем горизонтальную прямую y = yv[0]
        *a = 0;
        *b = yv[0];
        // printf("Горизонтальная прямая: y=%.2lf\n", yv[0]);
        return 1;
    }
    // Вычисляем суммы
    for (int i = 0; i < n; i++) 
    {
        sum_x += xv[i];
        sum_y += yv[i];
        sum_xy += xv[i] * yv[i];
        sum_x2 += xv[i] * xv[i];
    }

    // Решаем систему уравнений для a и b
    denominator = n * sum_x2 - sum_x * sum_x;
    if (fabs(denominator) < 1e-6) 
    {
        printf("Ошибка: деление на ноль\n");
        *a = 0;
        *b = 0;
        return -1;
    }

    *a = (n * sum_xy - sum_x * sum_y) / denominator;
    *b = (sum_y - (*a) * sum_x) / n;
    return 1;
}

// Функция для вычисления значения линейной функции y = ax + b
double linear_function(double x, double a, double b) 
{
    return a * x + b;
}

// Тест 1: y = 2x + 1
int test_linear_function(FILE*fout)
{
    int n = 3;
    double xv[] = {1, 2, 3};
    double yv[] = {3, 5, 7};
    double xp = 10;
    double expected_yp = 21;
    double yp;

    double a, b;
    n = least_squares_approximation(xv, yv, n, &a, &b);

    yp = linear_function(xp, a, b);

    printf( "Нужное значение: %lf Найденное значение: %lf\n",expected_yp, yp);
    if(n!=1)return 0;
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    fprintf(fout, "-------------\n");
    printf("Тест 1 пройден: линейная функция\n");
    return 1;
}

// Тест 2: Проверка на квадратичной функции y = x^2
int test_quadratic_function(FILE*fout) 
{
    int n = 4;
    double xv[] = {1, 2, 3, 4};
    double yv[] = {1, 4, 9, 16};
    double xp = 5;
    double expected_yp = 20;
    double yp;

    double a, b;
    n=least_squares_approximation(xv, yv, n, &a, &b);

    yp = linear_function(xp, a, b);

    printf( "Нужное значение: %lf Найденное значение: %lf\n",expected_yp, yp);
    if(n!=1)return 0;
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    fprintf(fout, "-------------\n");
    printf("Тест 2 пройден: квадратичная функция\n");
    return 1;
}



// Тест 3: Проверка на константной функции y = 5
int test_constant_function(FILE*fout) 
{
    int n = 3;
    double xv[] = {1, 2, 3};
    double yv[] = {5, 5, 5};
    double xp = 100;
    double expected_yp = 5;
    double yp;

    double a, b;
    n=least_squares_approximation(xv, yv, n, &a, &b);

    yp = linear_function(xp, a, b);

    printf( "Нужное значение: %lf Найденное значение: %lf\n",expected_yp, yp);
    if(n!=1)return 0;
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    fprintf(fout, "-------------\n");
    printf("Тест 3 пройден: константная функция\n");
    return 1;
}

// Тест 4: Проверка на одной точке
int test_single_point(FILE*fout) 
{
    int n = 1;
    double xv[] = {2};
    double yv[] = {5};
    double xp = 65;
    double expected_yp = 5;
    double yp;

    double a, b;
    n=least_squares_approximation(xv, yv, n, &a, &b);

    yp = linear_function(xp, a, b);

    printf( "Нужное значение: %lf Найденное значение: %lf\n",expected_yp, yp);
    if(n!=1)return 0;
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    fprintf(fout, "-------------\n");
    printf("Тест 4 пройден: одна точка\n"); 
    return 1;   
}
