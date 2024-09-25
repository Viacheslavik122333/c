#include"task23.h"

int task23(FILE *fin)
{
    int a, tmp, count=1, sum=0, num=0, tmpsum=0, res=0;  

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }
    while (fscanf(fin, "%d", &a) == 1)
    {
        tmpsum = sum;
        if (a == tmp)
        {
            count++;
            num=a;
        }
        else 
        {
            sum = count*num;
            count=1;
            num=0;
        }
        if(sum>tmpsum)
        {
            res=sum;
        }
        tmp = a;
    }
    if(count!=1)
    {
        sum = a*count;
        if(sum>res)
        {
            res=sum;
        }

    }
    
    fclose(fin);
    return res;
}