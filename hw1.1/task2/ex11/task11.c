#include"task11.h"

void task11(int *arr, int size)
{
    int sum=0;
    for (int i=0; i<size; i++, arr++)
    {
        sum+=*arr;
        *arr=sum;
    }    
}

