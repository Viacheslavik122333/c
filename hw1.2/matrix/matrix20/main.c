#include "header.h"
// Молчанов Вячеслав 108 группа

int main(void)
{
    int M, N; // вводные данные по задаче 
    int m, n, tmpn; // размеры матрицы (tmpn - кол-во столбцов после изменения)
    int **mat;
    FILE* Mat1;
    FILE* Mat2;
    FILE* Mat3;
    Mat1 = fopen("Mat1.txt", "r");
    Mat2 = fopen("Mat2.txt", "r");
    Mat3 = fopen("Mat3.txt", "r");

    // TEST 1 Базовый случай
    printf("TEST 1: ");
    M = 3; N = 5; // данные числа
    m = 3; // количество строк
    n = 4; // количество столбцов

    mat = mallocMatrix(m, n); // выделение памяти 
    fillMatrix(mat, m, n, Mat1); // заполнение матрицы
    fclose(Mat1);
    printf("M = %d, N = %d\n", M, N);
    printf("original matrix:\n");
    PrintMatrix(mat, m, n); // вывод матрицы
    tmpn = SortMatrix(mat, m, n, M, N); // сама функция
    printf("modified matrix:\n"); 
    PrintMatrix(mat, m, tmpn);
    freeMatrix(mat, m); // очищиние памяти выделенной под матрицу
    printf("\n");


    // TEST 2 Нечетное количество столбцов в подмножестве
    printf("TEST 2: ");
    M = 2; N = 3;
    m = 2; n = 5; 

    mat = mallocMatrix(m, n);
    fillMatrix(mat, m, n, Mat2);
    fclose(Mat2);
    printf("M = %d, N = %d\n", M, N);
    printf("original matrix:\n");
    PrintMatrix(mat, m, n);
    tmpn = SortMatrix(mat, m, n, M, N);
    printf("modified matrix:\n");
    PrintMatrix(mat, m, tmpn);
    freeMatrix(mat, m);
    printf("\n");

    // TEST 3 Нет столбцов, подходящих под условие
    printf("TEST 3: ");
    M = 2; N = 3; 
    m = 2; n = 3; 

    mat = mallocMatrix(m, n);
    fillMatrix(mat, m, n, Mat3);
    fclose(Mat3);
    printf("M = %d, N = %d\n", M, N);
    printf("original matrix:\n");
    PrintMatrix(mat, m, n);
    tmpn = SortMatrix(mat, m, n, M, N);
    printf("modified matrix:\n");
    PrintMatrix(mat, m, tmpn);
    freeMatrix(mat, m);
    printf("\n");

    return 0;
}