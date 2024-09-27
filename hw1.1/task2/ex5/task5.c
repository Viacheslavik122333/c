#include"task5.h"

int task5(int *arr1, int size1, int *arr2, int size2, int *arr3)
{
    int size3=0;
    int *tmparr3 = arr3;
    int *ptr = arr3;
    int count=0;

    *arr3 = *arr1;
    arr1++;
    arr3++;

    for(int i=1; i<size1; i++, arr1++)
    {
        for (int j=0; j<=i; j++, ptr++)
        {
            if(*arr1 == *ptr)
            {
                count++;
            }
        }
        if(count==0)
        {
            *arr3 = *arr1;
            arr3++;
            size3++;
        }
        else
        {
            count=0;
        }
        ptr=tmparr3;
    }
    count=0;

    // 1 1 2 2 3 4 4 5

    for(int i=1; i<size2; i++, arr2++)
    {
        for (int j=0; j<=(size1+i); j++, ptr++)
        {
            if(*arr2 == *ptr)
            {
                count++;
            }
        }
        if(count==0)
        {
            *arr3 = *arr2;
            arr3++;
            size3++;
        }
        else
        {
            count=0;
        }
        ptr=tmparr3;
    }
    
    return size3;
}



