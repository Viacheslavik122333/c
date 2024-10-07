#include"task20.h"

void task20(int *arr1, int size1, int *arr2, int size2, int *arr3)
{
    int k = size1+size2;
    int a=0, b = 0;

    for(int i = 0; i<k; i++)
    {
        if(*arr1 <= *arr2 && a<size1)
        {
            *arr3 = *arr1;
            arr1++;
            arr3++;
            a++;
        }
        else if ((*arr1 > *arr2 && b<size2))
        {
            *arr3 = *arr2;
            arr2++;
            arr3++;
            b++;
        }
        else
        {
            if(a<size1)
            {
                *arr3 = *arr1;
                arr1++;
                arr3++;
            }
            else
            {
                *arr3 = *arr2;
                arr2++;
                arr3++;
            }
        }
    }
}



