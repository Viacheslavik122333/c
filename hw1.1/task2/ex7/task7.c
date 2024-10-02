#include"task7.h"

int task7(int *arr, int size)
{
    int res=0, count=0, tmpcount=0;
    int *tmparr = arr;
    int *Arr = arr;
    for (int i=0; i<size; i++, arr++)
    {
        for(int j=0; j<size; j++, tmparr++)
        {
            if(*arr == *tmparr)
            {
                count++;
            }
        }
        if(count>tmpcount)
        {
            tmpcount=count;
            res = *arr;
        }
        tmparr = Arr;
        count = 0;
    }
    return res;
}
