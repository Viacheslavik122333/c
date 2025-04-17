#include "header.h"

int main(void) 
{
    // Запуск тестов
    FILE*fout = fopen("output.txt", "w");
    test_linear_function(fout);
    test_quadratic_function(fout);
    test_constant_function(fout);
    test_single_point(fout);
    fclose(fout);
    return 0;
}
