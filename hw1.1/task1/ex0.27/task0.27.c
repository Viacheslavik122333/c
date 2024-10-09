#include"task0.27.h"

double task27(int *arr,int size)
{
    double res=0;
    int count=1;
    double allcount=0;
    for (int i=0; i<size; i++, arr++)
    {
        if(*arr == *(arr+1))
        {
            count++;
        }
        else
        {
            if(count!=1)
            {
                allcount++;
                res+=*arr;
            }
            count=1;
        }
        
    }
    if(count!=1)
    {
        allcount++;
        res+=*arr;
    }
    if(allcount<1e-6)
    {
        allcount=1;
    }
    return (res/allcount);
}