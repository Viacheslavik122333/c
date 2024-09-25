#include"task24.h"

double task24(FILE *fin)
{
    int a, tmp, count=0;   
    double tmpcount=0, sum=0;

    // 1 2 2 3 2 1 2 1

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }
    while (fscanf(fin, "%d", &a) == 1)
    {
        if(tmp < a || a == tmp)
        {
            count++;
        }
        else //(tmp > a)
        {
            if(count!=0)
            {
                sum+=tmp;
                tmpcount++;
                count = 0;
            }
            count = 0;
        }
        tmp = a;
    }
    fclose(fin);
    return sum/tmpcount;
}