#include "header.h"

int main(void) 
{
    // Запуск тестов
    FILE*fout = fopen("output.txt", "w");
    int res=0;
    res += test_linear_function(fout);
    res += test_quadratic_function(fout);
    res += test_constant_function(fout);
    res += test_multiple_points(fout);
    res += test_single_point(fout);
    fclose(fout);
    if(res != 0)
    {
        printf("Прошли не все тесты :( \n");
        return -1;
    }
    printf("Все тесты пройдены успешно :) \n");
    return 0;
}