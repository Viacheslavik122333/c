#include"task25.h"

int task25(FILE *fin)
{
    int a, tmp, count=0, dist=0, tmpDist=0, extremum=0;   

    // 1 2 2 3 2 1 2 4 5 4 3 2 1 0 -1

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }
    while (fscanf(fin, "%d", &a) == 1)
    {
        // count++;
        if(tmp < a || a == tmp)
        {
            if(extremum==1)
            {
                count++;
            }
        }
        else if (tmp > a)
        {
            if(count!=0 || extremum==0)
            {
                extremum=1;
                tmpDist = count;
                count = 0;
            }
            else
            {
                count++;
            }
        }
        if(tmpDist>dist)
        {
            dist = tmpDist;
        }
        tmp = a;
    }
    fclose(fin);
    return dist;
}