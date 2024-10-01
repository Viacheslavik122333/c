#include"task9.h"

int task9(FILE *fin, int x1, int x2, int c1, int c2, int c3, int b)
{
    int res=1, x3, tmp;
    while (fscanf(fin, "%d", &x3)==1)
    {
        tmp = c1*x1+c2*x2+c3*x3;
        if(tmp != b)
        {
            res=0;
        }
        x1=x2;
        x2=x3;
    }
    return res;
}