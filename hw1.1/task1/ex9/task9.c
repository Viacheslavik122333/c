#include"task9.h"

int task9(FILE *fin, int x1, int x2, int c1, int c2, int c3, int b)
{
    int res=1, x3, tmp=0;
    if(fscanf(fin, "%d", &x3)!=1)
    {
        return 1;
    }
    tmp = c1*x1+c2*x2+c3*x3;
    if((tmp-b)<1e-6)
    {
        x1=x2;
        x2=x3;
        if(task9(fin, x1, x2, c1, c2, c3, b)==1)
        {
            return 1;
        }
        else
        {
            res=0;
        }
    }
    else 
    {
        res=0;
    }

    return res;
}