#include"task29.h"

void task29(FILE *fin, FILE *fout, int x)
{
    int tmp, a;
    int polynom=0, derivative=0; 
    int i=1;

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
    }
    polynom = tmp;
    while (fscanf(fin, "%d", &a) == 1)
    {
        polynom += a * pow(x, i);
        derivative += a * i * pow(x, i-1);
        i++;
    }
    
    fclose(fin);
    fprintf(fout, "polynom:%d, derivative:%d", polynom, derivative);
}
