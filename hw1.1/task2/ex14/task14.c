#include"task14.h"

void task14(double *arr, int size)
{
    double psum=0, tmp=0;
    double *tmparr = arr;
    double *Tmparr = arr;
    int count=1, count2=0, j=0; 
    arr++;
    for (int i=0; i<size-1; i++, arr++)
    {
        if((*arr - *(arr-1))<1e-6 && (*arr - *(arr-1))>-(1e-6))
        {
            if(count==1)
            {
                tmparr = arr;
                j=i;
                while((*tmparr - *(tmparr-1))<1e-6 && (*tmparr - *(tmparr-1))>-(1e-6) && j<size-2)
                {
                    tmparr++;
                    j++;
                } // 5 6 6 4
                if(tmparr == Tmparr + (size-1) && (*tmparr - *(tmparr-1))<1e-6 && (*tmparr - *(tmparr-1))>-(1e-6))
                {
                    psum = (tmp)/2;
                    *(Tmparr + (size-1)) = psum;
                    count2 = 1;
                }
            }
            count++;
            if(count2==1)
            {
                psum = (tmp)/2;
                *(arr-1) = psum;
            }
            else
            {
                psum = (tmp + *tmparr)/2;
                *(arr-1) = psum;
            }
        }
        else
        {
            tmp=*(arr-1);
            if(count>1)
            {
                *(arr-1) = psum;
            }
            count=1;
        }
    }
}


