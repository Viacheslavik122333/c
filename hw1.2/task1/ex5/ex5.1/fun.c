#include"header.h"

double lagrange_interpolation(double x, double xv[], double yv[], int n) 
{
    double res = 0;

    for (int i = 0; i < n; i++) 
    {
        double tmp = yv[i];
        for (int j = 0; j < n; j++) 
        {
            if (j != i) 
            {
                tmp *= (x - xv[j]) / (xv[i] - xv[j]);
            }
        }
        res += tmp;
    }

    return res;
}


// Тест 1: y = 2x + 1
int test_linear_function(FILE* fout) 
{
    int n = 2;
    double xv[] = {1, 2};
    double yv[] = {3, 5}; 

    double xp = 1.5;
    double expected_yp = 4.0;
    double yp = lagrange_interpolation(xp, xv, yv, n);

    if(fabs(yp - expected_yp) < 1e-6)
    {
        fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    }
    else
    {
        printf("Тест 1 не пройден\n");
        return -1;
    }
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
    double yp = lagrange_interpolation(xp, xv, yv, n);
    
    if(fabs(yp - expected_yp) < 1e-6)
    {
        fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    }
    else
    {
        printf("Тест 2 не пройден\n");
        return -1;
    }
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
    double yp = lagrange_interpolation(xp, xv, yv, n);
    
    if(fabs(yp - expected_yp) < 1e-6)
    {
        fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    }
    else
    {
        printf("Тест 3 не пройден\n");
        return -1;
    }
    printf("Тест 3 пройден: константная функция\n");
    fprintf(fout, "-------------\n");
    return 0;
}

// Тест 4: Проверка на нескольких точках y = x^2
int test_multiple_points(FILE* fout) 
{
    int n = 4;
    double xv[] = {1, 2, 3, 4};
    double yv[] = {1, 4, 9, 16};

    double xp[] = {1.5, 2.5, 3.5};
    double expected_yp[] = {2.25, 6.25, 12.25};

    for (int i = 0; i < 3; i++) {
        double yp = lagrange_interpolation(xp[i], xv, yv, n);
        if(fabs(yp - expected_yp[i]) < 1e-6)
        {
            fprintf(fout, "%.2lf %.2lf\n", xp[i], yp);
        }
        else
        {
            printf("Тест 4 не пройден\n");
            return -1;
        }
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
    double yp = lagrange_interpolation(xp, xv, yv, n);

    if(fabs(yp - expected_yp) < 1e-6)
    {
        fprintf(fout, "%.2lf %.2lf\n", xp, yp);
    }
    else
    {
        printf("Тест 5 не пройден\n");
        return -1;
    }
    printf("Тест 5 пройден: одна точка\n");
    fprintf(fout, "-------------\n");
    return 0;
}