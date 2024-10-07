#include"task19.h"

void task19(int *ptr, int size, int x)
{
    int *Ptr = ptr+size-2;
    int *left = ptr;
    int *right = ptr+size-2;
    int k = size;
    if(x>*Ptr)
    {
        *(Ptr+1) = x;
    }
    else if (x<*ptr)
    {
        sdvig(Ptr, left);
        *(left+1) = *left;
        *left = x;
    }
    else
    {
        while (1)
        {
            if(*left <= x && *(left+1)>=x)
            {
                break;
            }

            if((*left + *right)/2 <= x)
            {
                right-=(k+1)/2;
                k=k/2+1;
            }
            else
            {
                left+=(k+1)/2;
                k=k/2+1;
            }
        } 
        sdvig(Ptr, left);
        *(left+1) = x;
    }
    
}
// 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 x = 10 left != (right+1)

void sdvig(int *ptr, int *tmpptr)
{
    while (ptr != tmpptr)
    {
        *(ptr+1) = *ptr;
        ptr--;
    }
}

