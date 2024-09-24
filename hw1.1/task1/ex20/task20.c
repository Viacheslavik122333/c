#include"task20.h"

int task20(FILE *fin)
{
    int a, tmp, quantity=0, count=1;  

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }

    while (fscanf(fin, "%d", &a) == 1)
    {
        if (a == tmp)
        {
            count++;
        }
        else 
        {
            if(count>quantity && count>1)
            {
                quantity=count;
            }
            count=1;
        }
        tmp = a;
    }
    if(count!=1)
    {
        quantity = count;
    }
    
    fclose(fin);
    return quantity;
}