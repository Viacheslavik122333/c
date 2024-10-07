#include"task13.h"

void task13(double *arr, int size)
{
    double psum=0;
    arr++;
    for(int i = 2; i<size; i++, arr++)
    {
        psum = (*(arr-1) + *(arr+1))/2;
        *arr=psum;
    }
}

