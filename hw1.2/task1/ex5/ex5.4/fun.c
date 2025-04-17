#include"header.h"

double hermite_interpolation(double x, double xv[], double yv[], double dyv[], int n) 
{
    if (n == 1) 
    {
        if (fabs(x - xv[0]) < 1e-6) 
        { // Проверка, что x совпадает с xv[0]
            return yv[0];
        } 
        else 
        {
            printf("Ошибка: интерполяция невозможна для одной точки, если x != xv[0].\n");
            return 0;
        }
    }
    for (int i = 0; i < n - 1; i++) 
    {
        if (x >= xv[i] && x <= xv[i + 1]) 
        {
            double x0 = xv[i];
            double x1 = xv[i + 1];
            double y0 = yv[i];
            double y1 = yv[i + 1];
            double dy0 = dyv[i];
            double dy1 = dyv[i + 1];

            // Вычисление коэффициентов кубического многочлена
            double h = x1 - x0;
            double t = (x - x0) / h;
            double h00 = (1 + 2 * t) * (1 - t) * (1 - t);
            double h10 = t * (1 - t) * (1 - t);
            double h01 = t * t * (3 - 2 * t);
            double h11 = t * t * (t - 1);

            // Формула эрмитовой интерполяции
            return h00 * y0 + h10 * h * dy0 + h01 * y1 + h11 * h * dy1;
        }
    }
    return 0;
}

// Тест 1: y = 2x + 1
int test_linear_function(FILE* fout) 
{
    int n = 2;
    double xv[] = {1, 2};
    double yv[] = {3, 5};
    double dyv[] = {2, 2}; 

    double xp = 1.5;
    double expected_yp = 4.0;
    double yp = hermite_interpolation(xp, xv, yv, dyv, n);

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
    double dyv[] = {2, 4, 6};

    double xp = 2.5;
    double expected_yp = 6.25;
    double yp = hermite_interpolation(xp, xv, yv, dyv, n);
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
    double dyv[] = {0, 0, 0}; 

    double xp = 2.5;
    double expected_yp = 5.0;
    double yp = hermite_interpolation(xp, xv, yv, dyv, n);
    
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
    double dyv[] = {2, 4, 6, 8};

    double xp[] = {1.5, 2.5, 3.5};
    double expected_yp[] = {2.25, 6.25, 12.25};

    for (int i = 0; i < 3; i++) {
        double yp = hermite_interpolation(xp[i], xv, yv, dyv, n);
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
    double dyv[] = {0};

    double xp = 2;
    double expected_yp = 5.0;
    double yp = hermite_interpolation(xp, xv, yv, dyv, n);

    printf( "Нужное значение: %lf Найденное значение: %lf\n", expected_yp, yp);
    fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    printf("Тест 5 пройден: одна точка\n");
    fprintf(fout, "-------------\n");
    return 0;
}
