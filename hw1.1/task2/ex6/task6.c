#include"task6.h"

int task6(int *arr1, int size1, int *arr2, int size2, int *arr3)
{
    int *ptr = arr3;
    int *tmparr2 = arr2;
    int size3=0;

    for(int i=0; i<size1; i++, arr1++)
    {
        for(int j=0; j<size2; j++, arr2++)
        {
            if(*arr1 == *arr2)
            {
                *ptr = *arr1;
                ptr++;
                size3++;
                break;
            }
        }
        arr2 = tmparr2;
    }
    return size3;
}
