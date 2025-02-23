#include "header.h"

int main(void) 
{
    double a[] = {0, 10, 5, 0, 6, 23, 0, 0, 0, 2, -10};
    double b[] = {2, 20, 4, 3, 6, 23, 2, 2, 2, 10, 10};
    double epss[11], answer[11];
    const char* errors[6];
    double root, (*func[11])(double) = {&f0, &f1, &f2, &f3, &f4,  &f5,  &f6,  &f7,  &f8, &f9, &f10};
    int error=0, count=0;
    setlocale(LC_ALL, "rus");
    errors[1] = "Некорректный отрезок";
    errors[2] = "Некорректный ввод eps";
    errors[3] = "Корень вне отрезка";
    errors[4] = "Деление на 0";

    for(int i=0; i<11; i++)
        {epss[i] = 1e-6; answer[i] = sqrt(2);}
    epss[3] = -1e-6; epss[6] = 1e-15; epss[7] = 1; epss[8] = 10; epss[9] = 10;
    answer[4] = 6; answer[5] = 6; answer[10] = 0; 

    printf("\n--------division--------\n\n");
    for (int i=0; i<11; i++)
    {
        root = division(func[i], a[i], b[i], epss[i], &error, &count);
        if((error == 0) && (fabs(root - answer[i]) < epss[i])) 
        {
        printf("test %d success! (%d iterations)\n", i+1, count);
        }
        else 
        {
        printf("test %d failure! %s\n", i+1, errors[error]);
        }
        count=0;
    }
    // test 1: Корень sqrt2 на отрезке [0,2]
    // test 2: Нет корней на отрезке [10,20]
    // test 3: Неправильно задан отрезок
    // test 4: Неправильно задан eps
    // test 5: Корень на вырожденном отрезке [6,6]
    // test 6: Нет корня на вырожденном отрезке [23,23]
    // test 7:  eps = 1e-15 Корень sqrt2 на отрезке [0,2]
    // test 8:  eps = 1 Корень sqrt2 на отрезке [0,2]
    // test 9:  eps = 10 Корень sqrt2 на отрезке [0,2]
    // test 10:  eps = 10 Нет корня sqrt2 на отрезке [2,10]
    // test 11: Корень x = 0 f(x)=e^(x)-1 на отрезке [-10,10]





    printf("\n--------newton--------\n\n");

    // test 1 Корень sqrt2 начальное приближение 10
    root = newton(f0, f11, 10, 1e-6, &error, &count);
    if((error == 0) && (fabs(root - sqrt(2))<1e-6)) 
    {
        printf("test 1 success! (%d iterations)\n", count);
    }
    else 
    {
        printf("test 1 failure! %s\n", errors[error]);
    }

    // test 2 Корень sqrt2 начальное приближение 50, eps =1e-12
    root = newton(f0, f11, 50, 1e-12, &error, &count);
    if((error == 0) && (fabs(root - sqrt(2))<1e-12)) {
        printf("test 2 success! (%d iterations)\n", count);
    }
    else 
    {
        printf("test 2 failure! %s\n", errors[error]);
    }

    // test 3  Некорректный eps
    root = newton(f0, f11, 10, -1, &error, &count);
    if((error == 0) && (fabs(root - sqrt(2))<1e-6)) 
    {
        printf("test 3 success! (%d iterations)\n", count);
    }
    else 
    {
        printf("test 3 failure! %s\n", errors[error]);
    }

    // test 4 f(x)=sinx. Корень 0 начальное приближение 1, eps =1e-6
    root = newton(sin, cos, 1, 1e-6, &error, &count);
    if((error == 0) && (fabs(root)<1e-6)) 
    {
        printf("test 4 success! (%d iterations)\n", count);
    }
    else 
    {
        printf("test 4 failure! %s\n", errors[error]);
    }

    // test 5 Возьмем линейную функцию f(x)=x. 
    root = newton(f12, f13, 10, 1e-6, &error, &count);
    if((error == 0) && (fabs(root)<1e-6)) 
    {
        printf("test 5 success! (%d iterations)\n", count);
    }
    else {
        printf("test 5 failure! %s\n", errors[error]);
    }





    printf("\n--------chord--------\n\n");
    for (int i=0; i<11; i++)
    {
        root = chord(func[i], a[i], b[i], epss[i], &error, &count);
        if((error == 0) && (fabs(root - answer[i]) < epss[i])) 
        {
        printf("test %d success! (%d iterations)\n", i+1, count);
        }
        else 
        {
        printf("test %d failure! %s\n", i+1, errors[error]);
        }
        count=0;
    }
    // test 1: Корень sqrt2 на отрезке [0,2]
    // test 2: Нет корней на отрезке [10,20]
    // test 3: Неправильно задан отрезок
    // test 4: Неправильно задан eps
    // test 5: Корень на вырожденном отрезке [6,6]
    // test 6: Нет корня на вырожденном отрезке [23,23]
    // test 7:  eps = 1e-15 Корень sqrt2 на отрезке [0,2]
    // test 8:  eps = 1 Корень sqrt2 на отрезке [0,2]
    // test 9:  eps = 10 Корень sqrt2 на отрезке [0,2]
    // test 10:  eps = 10 Нет корня sqrt2 на отрезке [2,10]
    // test 11: Корень x = 0 f(x)=e^(x)-1 на отрезке [-10,10]

    return 0;
}