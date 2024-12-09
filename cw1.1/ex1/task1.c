#include"task1.h"

void fun(FILE*fin, FILE*fout)
{
    int x, a=0, b=0, c=0;
    int tmp;
    tmp = fscanf(fin, "%d", &x);
    if(tmp == 0){fprintf(stderr, "Incorect data\n"); return;}
    if (tmp == -1){fprintf(stderr, "Empty file\n"); return;}
    fprintf(fout, "0: %d\n", x);
    a+=x;
    tmp = fscanf(fin, "%d", &x);
    if(tmp!=1){return;}
    fprintf(fout, "1: %d\n", x);
    b+=x;
    tmp = fscanf(fin, "%d", &x);
    if(tmp!=1){return;}
    fprintf(fout, "2: %d\n", x);
    c+=x;
    while(fscanf(fin, "%d", &x)==1)
    {
        if(a<=b)
        {
            if(a<=c)
            {
                a+=x;
                fprintf(fout, "0: %d\n", x);
            }
            else
            {
                c+=x;
                fprintf(fout, "2: %d\n", x);
            }
        }
        else //b<a
        {
            if(b<=c)
            {
                b+=x;
                fprintf(fout, "1: %d\n", x);
            }
            else
            {
                c+=x;
                fprintf(fout, "2: %d\n", x);
            }
        }
    }
}