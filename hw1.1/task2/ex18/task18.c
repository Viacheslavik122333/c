#include"task18.h"

void task18(int *arr, int size)
{
    int tmp1=1, tmp2=1;
    int *ptr = arr+1;
    int count=1;
    *arr = 1;
    if(size == 1)
    {
        *arr = 1;
    }
    else if(size == 2)
    {
        *(arr+1) = 1;
    }
    else
    {
        *(arr+1) = 1;
        arr++;
        while(count < size-1)
        {
            for(int i=0; i<count; i++) 
            {
                tmp2 = *arr;
                *arr = *arr + tmp1;
                tmp1=tmp2;
                arr++; 
            }
            arr = ptr;
            count++;
        }
        
    }
}



