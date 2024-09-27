#include"task30.h"

void task30(FILE *fin, FILE *fout, double x)
{
    int tmp, a;
    double polynom=0, derivative=0; 
    int i=0, j=0;

    if (fscanf(fin, "%d", &tmp) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
    }
    polynom = tmp;
    while (fscanf(fin, "%d", &a) == 1)
    {
        polynom += (double)a * pow(x, i-1);

        derivative += (double)a * (j+1) * pow(x, i);

        i--;
        j++;

    }
    polynom *=pow(x,j);
    derivative *= pow(x,j-1);
    fclose(fin);
    fprintf(fout, "polynom:%.0lf, derivative:%lf", polynom, derivative);
}
