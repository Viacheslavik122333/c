#include"task3.h"

void task3(int *arr, const size_t size)
{
    int tmp = *arr;
    arr--;
    for (int i=size-1; i>0; i--, arr--)
    {
        *(arr+1)=*arr;
        printf("%d\n", *arr);

    }
    arr++;
    *arr = tmp;
}
// void swap(int *a, int *b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
//1 2 3 4 5 6 

