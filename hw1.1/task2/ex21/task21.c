#include"task21.h"

void task21(int a[], int size)
{
    int k = size/2;
    int f=0;
    for (int i=k; i>0; i--)
    {
        for(int j = 0; j<i; j++)
        {
            swap(a, 2*j+f);
        }
        f++;
    }
    
}
void swap(int a[], int l)
{
    int tmp = a[l];
    a[l] = a[l+1];
    a[l+1] = tmp;
}

