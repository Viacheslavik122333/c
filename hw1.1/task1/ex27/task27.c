#include"task27.h"

double task27(FILE *fin)
{
    int a, num=0, count=1, allcount=0, tmp;  
    double sr=0;

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }

    while (fscanf(fin, "%d", &a) == 1)
    {
        if(tmp == a)
        {
            num = tmp;
            allcount++;
            count++;
        }
        else
        {
            if(count!=1)
            {
                allcount++;
            }
            sr+=count*num;
            count=1;
            num=0;
        }
        tmp = a;
    }
    if(count!=1)
    {
        allcount++;
        sr+=count*num;
    }
    if(allcount==0)
    {
        allcount=1;
    }
    fclose(fin);
    return sr/allcount;
}