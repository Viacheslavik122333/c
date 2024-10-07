#include"task10.h"

int task10(int *arr, int size)
{
    int count=0;
    for (int i=0; i<size; i++, arr++)
    {
        if(*arr < 0)
        {
            sdvig(arr, (size-i-1));
            arr--;
            count++;
        }
    }    
    return (size-count);
}

void sdvig(int *arr, int N)
{
    int i=0;
    while(i<N)
    {
        *arr = *(arr+1);
        arr++;
        i++;
    }
}
