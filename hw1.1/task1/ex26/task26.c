#include"task26.h"

double task26(FILE *fin)
{
    int a, tmp, count=1; 
    double sr=0, sum;  

    // 1 1 2 3 3 3 4 3 3

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }
    sum = tmp;
    while (fscanf(fin, "%d", &a) == 1)
    {
        if(tmp!=a)
        {
            sum+=a;
            count++;
        }
        tmp = a;
    }
    // Я тут не понял вопрос, учитываем ли мы кол-во чисел на постоянном участке. Я сделал, что мы не учитываем.
    sr = sum/count;
    fclose(fin);
    return sr;
}