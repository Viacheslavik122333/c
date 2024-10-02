#include"task8.h"

int task8(int *arr, int size)
{
    int *tmparr = arr;
    int *Arr = arr;
    // int N = size;
    for (int i=0; i<size; i++, arr++)
    {
        for(int j=0; j<size; j++)
        {
            if(*arr == *tmparr && arr!=tmparr)
            {
                sdvig(tmparr, size-j-1);
                size--;
            }
            else
            {
                tmparr++;
            }
        }
        tmparr = Arr;
    }
    return size;
}
// 6 4 4 4 5 10

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
