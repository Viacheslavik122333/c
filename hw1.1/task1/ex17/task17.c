#include"task17.h"

int task17(FILE *fin)
{
    int b, quantity1=0, tmp=0, count=0;

    fscanf(fin, "%d", &tmp);
    
    while(fscanf(fin, "%d", &b) == 1)
    {
        if((b-tmp)>1e-12)
        {
            ++count;
        }
        if((tmp-b)>1e-12)
        {
            count=0;
        }
        if(count == 1)
        {
            quantity1++;
        }
        tmp=b;
    }
    fclose(fin);
    return quantity1;
}