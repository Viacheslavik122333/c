#include"task15.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    double a, x; 
    int size=0;

    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    while (fscanf(fin, "%lf", &a) == 1)
    {
        size++;
    }
    rewind(fin);

    double *tmparr = (double*)malloc(size * sizeof(double));
    double *arr = tmparr;

    for(int i=0; i<size; i++, arr++)
    {
        fscanf(fin, "%lf", &x);
        if(x<1e-12 && x>-1e-12){fprintf(fout, "Нули убери, про нули не сказанно, что с ними делать!!!"); return -1;}
        *arr=x;
    }
    arr=tmparr;

    task15(arr, size);

    arr = tmparr;

    for (int i=0; i<size; i++, arr++)
    {
        fprintf(fout, "%.1lf ", *arr);
    }

    free (tmparr);
    fclose(fin);
    fclose(fout);
    return 0;
}