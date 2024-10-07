#include"task22.h"

void task22(int a[], int size)
{
    int k = size/2;
    int f=k-1; // 2
    for (int i=0; i<k; i++)
    {
        for(int j = 0; j<i+1; j++)
        {
            swap(a, f+(2*j));
        }
        f--;//
    }
    
}
void swap(int a[], int l)
{
    int tmp = a[l];
    a[l] = a[l+1];
    a[l+1] = tmp;
}

