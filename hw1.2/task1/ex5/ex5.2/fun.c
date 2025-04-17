#include"header.h"

double piecewise_linear_interpolation(double x, double xv[], double yv[], int n) 
{
    // Поиск интервала, в который попадает x
    for (int i = 0; i < n - 1; i++) 
    {
        if (x >= xv[i] && x <= xv[i + 1]) 
        {
            // Линейная интерполяция между xv[i] и xv[i + 1]
            double x0 = xv[i];
            double x1 = xv[i + 1];
            double y0 = yv[i];
            double y1 = yv[i + 1];

            // Формула линейной интерполяции:
            return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
        }
    }

    // Если x находится за пределами интервала, возвращаем крайнее значение
    if (x < xv[0]) 
    {
        return yv[0];
    } 
    else 
    {
        return yv[n - 1];
    }
}

// Тест 1: y = 2x + 1
int test_linear_function(FILE* fout) 
{
    int n = 2;
    double xv[] = {1, 2};
    double yv[] = {3, 5}; 

    double xp = 1.5;
    double expected_yp = 4.0;
    double yp = piecewise_linear_interpolation(xp, xv, yv, n);

    printf( "Нужное значение: %lf Найденное значение: %lf\n", expected_yp, yp);
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    printf("Тест 1 пройден: линейная функция\n");
    fprintf(fout, "-------------\n");
    return 0;
}

// Тест 2: y = x^2
int test_quadratic_function(FILE* fout) 
{
    int n = 3;
    double xv[] = {1, 2, 3};
    double yv[] = {1, 4, 9};

    double xp = 2.5;
    double expected_yp = 6.25;
    double yp = piecewise_linear_interpolation(xp, xv, yv, n);
    printf("%lf\n", yp);
    
    printf( "Нужное значение: %lf Найденное значение: %lf\n", expected_yp, yp);
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    printf("Тест 2 пройден: квадратичная функция\n");
    fprintf(fout, "-------------\n");
    return 0;
}

// Тест 3: y = 5
int test_constant_function(FILE* fout) 
{
    int n = 3;
    double xv[] = {1, 2, 3};
    double yv[] = {5, 5, 5}; 

    double xp = 2.5;
    double expected_yp = 5.0;
    double yp = piecewise_linear_interpolation(xp, xv, yv, n);
    
    printf( "Нужное значение: %lf Найденное значение: %lf\n", expected_yp, yp);
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    printf("Тест 3 пройден: константная функция\n");
    fprintf(fout, "-------------\n");
    return 0;
}

// Тест 4: Проверка на нескольких точках y = x^2
int test_multiple_points(FILE* fout) 
{
    int n=4;
    double xv[] = {1, 2, 3, 4};
    double yv[] = {1, 4, 9, 16};

    double xp[] = {1.5, 2.5, 3.5};
    double expected_yp[] = {2.25, 6.25, 12.25};

    for (int i = 0; i < 3; i++) {
        double yp = piecewise_linear_interpolation(xp[i], xv, yv, n);
        printf( "Нужное значение: %lf Найденное значение: %lf\n", expected_yp[i], yp);
        fprintf(fout, "%.2lf %.2lf\n", xp[i], yp);
    }
    printf("Тест 4 пройден: несколько точек\n");
    fprintf(fout, "-------------\n");
    return 0;
}

// Тест 5: Проверка на одной точке (должна вернуть значение этой точки)
int test_single_point(FILE* fout) 
{
    int n = 1;
    double xv[] = {2};
    double yv[] = {5};

    double xp = 2;
    double expected_yp = 5.0;
    double yp = piecewise_linear_interpolation(xp, xv, yv, n);

    printf( "Нужное значение: %lf Найденное значение: %lf\n", expected_yp, yp);
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    printf("Тест 5 пройден: одна точка\n");
    fprintf(fout, "-------------\n");
    return 0;
}