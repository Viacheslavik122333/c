#include"task13.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    double a, x; 
    int size=0;
    double *tmparr;
    double *arr;

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
        *arr=x;
    }
    arr=tmparr;

    task13(arr, size);

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