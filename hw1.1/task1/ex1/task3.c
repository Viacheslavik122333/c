#include"task3.h"

int task3(FILE *fin)
{
    int b, quantity1=0, tmp;

    fscanf(fin, "%d", &tmp);
    
    while(fscanf(fin, "%d", &b) == 1)
    {
        if((b-tmp)>1e-12)
        {
            ++quantity1;
        }
        tmp=b;
    }
    fclose(fin);
    return quantity1;
}