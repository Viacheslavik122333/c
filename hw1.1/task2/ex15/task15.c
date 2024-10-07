#include"task15.h"

void task15(double *arr, int size)
{
    double *tmparr = arr;
    int a=0;
    while(a>-1)
    {
        tmparr = arr;

        for(int i=0; i<size; i++)
        {
            if(*tmparr<0 && *(tmparr+1)>0)
            {
                swap(tmparr, tmparr+1);
                a++;
            }
            tmparr++;
        }

        if(a == 0)
        {
            break;
        }
        a=0;
    }
}

void swap (double *a, double *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


