#include "header.h"

// Пример функции f(x)
double f(double x) 
{
    return (x - 2) * (x - 2) + 3; // минимум в x = 2
}

// Линейная функция (не имеет минимума, но метод должен вернуть граничное значение)
double linear_function(double x) 
{
    return 2 * x + 1;
}

// Константная функция
double constant_function(double x) 
{
    x=5;
    return x;
}

// Функция с двумя минимумами
double multi_min_function(double x) 
{
    return sin(x) + 0.5 * x;
}

// Функция с "острым" минимумом (негладкая функция)
double sharp_min_function(double x) 
{
    return fabs(x - 3) + 2; // Минимум в x = 3
}

// Функция с минимумом в отрицательной области
double negative_min_function(double x) 
{
    return (x + 4) * (x + 4) - 5; // Минимум в x = -4
}

// Поиск трёх точек с помощью геометрической прогрессии
void find_three_points(double x0, double h, double *x1, double *x2, double *x3, double (*f)(double)) 
{
    *x1 = x0;
    *x2 = x0 + h;
    *x3 = x0 + 2 * h;

    // Увеличиваем шаг, пока не найдём три точки, где f(x1) > f(x2) < f(x3)
    while (f(*x1) < f(*x2)) 
    {
        *x1 = *x2;
        *x2 = *x3;
        *x3 = *x3 + h;
        h *= 2; // Увеличиваем шаг в геометрической прогрессии
    }
}

// Метод построения параболы
double parabolic_interpolation(double x1, double x2, double x3, double (*f)(double)) 
{
    double f1 = f(x1), f2 = f(x2), f3 = f(x3);

    // Формула для минимума параболы
    double numerator = (x2 - x1) * (x2 - x1) * (f2 - f3) - (x2 - x3) * (x2 - x3) * (f2 - f1);
    double denominator = (x2 - x1) * (f2 - f3) - (x2 - x3) * (f2 - f1);

    if (fabs(denominator) < 1e-10) 
    {
        return x2; // Избегаем деления на ноль
    }

    return x2 - 0.5 * numerator / denominator;
}

// Поиск минимума функции методом построения параболы
double find_minimum(double x0, double h, double eps, double (*f)(double)) 
{
    double x1, x2, x3;
    double x_min=x0;
    find_three_points(x0, h, &x1, &x2, &x3, f);
    do 
    {
        x_min = parabolic_interpolation(x1, x2, x3, f);

        if (x_min > x2) {
            x1 = x2;
            x2 = x_min;
        } else {
            x3 = x2;
            x2 = x_min;
        }
    } while (fabs(f(x_min) - f(x2)) > eps);

    return x_min;
}

// Тест 1: Квадратичная функция f(x) = (x - 2)^2 + 3
void test_quadratic_function(void) 
{
    double x0 = 0; // Начальная точка
    double h = 0.1; // Начальный шаг
    double eps = 1e-6; // Точность

    double min_x = find_minimum(x0, h, eps, f);
    double expected_min_x = 2.0; 
    double expected_f_min = 3.0; 

    printf("Тест 1: Квадратичная функция\n");
    printf("Ожидаемый минимум: x = %.6f, f(x) = %.6f\n", expected_min_x, expected_f_min);
    printf("Фактический минимум: x = %.6f, f(x) = %.6f\n", min_x, f(min_x));
    printf("\n");
}

// Тест 2: Линейная функция f(x) = 2x + 1 (не имеет минимума, но метод должен вернуть граничное значение)
void test_linear_function(void) 
{
    double x0 = 0; // Начальная точка
    double h = 0.1; // Начальный шаг
    double eps = 1e-6; // Точность

    double min_x = find_minimum(x0, h, eps, linear_function);
    double expected_min_x = x0;
    double expected_f_min = linear_function(x0); 

    printf("Тест 2: Линейная функция\n");
    printf("Ожидаемый минимум: x = %.6f, f(x) = %.6f\n", expected_min_x, expected_f_min);
    printf("Фактический минимум: x = %.6f, f(x) = %.6f\n", min_x, linear_function(min_x));
    printf("\n");

    // Проверка, что метод вернул начальную точку
    if (fabs(min_x - expected_min_x) < eps && fabs(linear_function(min_x) - expected_f_min) < eps) 
    {
        printf("Тест 2 пройден: метод вернул начальную точку.\n");
    } 
    else 
    {
        printf("Тест 2 не пройден: метод не вернул начальную точку.\n");
    }
    printf("\n");
}




// Тест 3: Константная функция f(x) = 5
void test_constant_function(void) 
{
    double x0 = 0; // Начальная точка
    double h = 0.1; // Начальный шаг
    double eps = 1e-6; // Точность

    double min_x = find_minimum(x0, h, eps, constant_function);
    double expected_min_x = x0; 
    double expected_f_min = 5.0;

    printf("Тест 3: Константная функция\n");
    printf("Ожидаемый минимум: x = %.6f, f(x) = %.6f\n", expected_min_x, expected_f_min);
    printf("Фактический минимум: x = %.6f, f(x) = %.6f\n", min_x, constant_function(min_x));
    printf("\n");
}

// Тест 4: Функция с двумя минимумами f(x) = sin(x) + 0.5 * x
void test_multi_min_function(void) 
{
    double x0 = 0; // Начальная точка
    double h = 0.1; // Начальный шаг
    double eps = 1e-6; // Точность

    double min_x = find_minimum(x0, h, eps, multi_min_function);
    double expected_min_x = -1.290; 
    double expected_f_min = multi_min_function(expected_min_x); 

    printf("Тест 4: Функция с двумя минимумами\n");
    printf("Ожидаемый минимум: x = %.6f, f(x) = %.6f\n", expected_min_x, expected_f_min);
    printf("Фактический минимум: x = %.6f, f(x) = %.6f\n", min_x, multi_min_function(min_x));
    printf("\n");
}

// Тест 5: Функция с "острым" минимумом f(x) = |x - 3| + 2
void test_sharp_min_function(void) 
{
    double x0 = 0; // Начальная точка
    double h = 0.1; // Начальный шаг
    double eps = 1e-6; // Точность

    double min_x = find_minimum(x0, h, eps, sharp_min_function);
    double expected_min_x = 3.0;
    double expected_f_min = 2.0;

    printf("Тест 5: Функция с острым минимумом\n");
    printf("Ожидаемый минимум: x = %.6f, f(x) = %.6f\n", expected_min_x, expected_f_min);
    printf("Фактический минимум: x = %.6f, f(x) = %.6f\n", min_x, sharp_min_function(min_x));
    printf("\n");
}

// Тест 6: Функция с минимумом в отрицательной области f(x) = (x + 4)^2 - 5
void test_negative_min_function(void) 
{
    double x0 = -10; // Начальная точка
    double h = 0.1; // Начальный шаг
    double eps = 1e-6; // Точность

    double min_x = find_minimum(x0, h, eps, negative_min_function);
    double expected_min_x = -4.0; 
    double expected_f_min = -5.0;

    printf("Тест 6: Функция с минимумом в отрицательной области\n");
    printf("Ожидаемый минимум: x = %.6f, f(x) = %.6f\n", expected_min_x, expected_f_min);
    printf("Фактический минимум: x = %.6f, f(x) = %.6f\n", min_x, negative_min_function(min_x));
    printf("\n");
}