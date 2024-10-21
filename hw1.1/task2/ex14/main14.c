#include"task14.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    double a, x; 
    int size=1;
    double *tmparr;
    double *arr;
    int flag;

    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }
    flag = fscanf(fin, "%lf", &a);
    if(flag == 0)
    {
        fprintf(stderr, "Incorect data\n");
        return -1;
    }
    if (flag == -1)
    {
        fprintf(stderr, "Empty file\n");
        return -1;
    }
    
    while (fscanf(fin, "%lf", &a) == 1){size++;}
    rewind(fin);

    tmparr = (double*)malloc(size * sizeof(double));
    arr = tmparr;

    for(int i=0; i<size; i++, arr++){fscanf(fin, "%lf", &x); *arr=x;}
    arr=tmparr;

    task14(arr, size);

    arr = tmparr;

    for (int i=0; i<size; i++, arr++){fprintf(fout, "%.1lf ", *arr);}

    free (tmparr);
    fclose(fin);
    fclose(fout);
    return 0;
}