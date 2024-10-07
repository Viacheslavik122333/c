#include"task17.h"

int task17(int *arr, int size, int a, int b)
{
    int res=0;
    int k = b-a+1;
    int *tmparr = arr;
    for(int i=0; i<k; i++)
    {
        res=0;
        for(int j=0; j<size; j++, tmparr++)
        {
            if(*tmparr == a+i)
            {
                res=1;
                break;
            }
        }
        if(res == 0)
        {
            break;
        }
        tmparr=arr;
    }
    return res;
}

