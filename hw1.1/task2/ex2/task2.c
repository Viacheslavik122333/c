#include"task2.h"

void task2(int *arr, const size_t size)
{
    for (int i=0; i<(int)(size/2); i++, arr++)
    {
        swap(arr, arr+(size-(i*2)-1));
    }
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

