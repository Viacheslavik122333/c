#include"task16.h"

int task16(double *arr1, int size)
{
    int res=0;
    double sum1=0, sum2=0;
    double *arr2 = arr1+(size-1);
    while (arr1-1 != arr2)
    {
        if(sum1<=sum2)
        {
            sum1+=*arr1;
            arr1++;
        }
        else
        {
            sum2+=*arr2;
            arr2--;
        }
    }
    if((sum1 - sum2) < 1e-6 && (sum1 - sum2) > -1e-6)
    {
        res=1;
    }
    return res;
}

