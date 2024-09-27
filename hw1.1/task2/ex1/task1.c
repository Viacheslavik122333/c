#include"task1.h"

bool task1(int *arr, const size_t size)
{
    int count=0, a=0;
    for (int i=0; i<(int)(size/2); i++, arr++)
    {
        if(*arr == *(arr+(size-(i*2)-1)))
        {
            // printf("%d %d\n", *arr, *(arr+(size-1-i*2)));
            count++;
        }
    }
    if(count == size/2)
    {
        a=1;
    }
    return a;
}
