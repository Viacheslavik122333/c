#include"task16.h"

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

    tmparr = (double*)malloc(size * sizeof(double));
    arr = tmparr;

    for(int i=0; i<size; i++, arr++)
    {
        fscanf(fin, "%lf", &x);
        *arr=x;
    }

    arr=tmparr;

    if(task16(arr, size))
    {
        fprintf(fout, "YES");
    }
    else
    {
        fprintf(fout, "NO");
    }

    free (tmparr);
    fclose(fin);
    fclose(fout);
    return 0;
}