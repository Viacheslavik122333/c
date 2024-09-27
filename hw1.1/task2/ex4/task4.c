#include"task4.h"

bool task4(int *arr1, int size1, int *arr2, int size2)
{
    int *tmparr2 = arr2;
    int count=0, a=1;
    for(int i=0; i<size1; i++)
    {
        for(int j=0; j<size2; j++)
        {
            if(*arr1 == *arr2)
            {
                count++;
                break;                
            }
            else
            {
                arr2++;
            }
        }
        if(count != 1)
        {
            a=0;
            break;
        }
        count=0;
        arr1++;
        arr2 = tmparr2;
    }
    return a;
}


