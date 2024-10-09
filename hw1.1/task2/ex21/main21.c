#include"task21.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int x; 
    int size=0;
    int *tmparr;
    int *arr;

    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    while (fscanf(fin, "%d", &x) == 1)
    {
        size++;
    }
    rewind(fin);

    tmparr = (int*)malloc(size * sizeof(int));
    arr = tmparr;

    for(int i=0; i<size; i++, arr++)
    {
        fscanf(fin, "%d", &x);
        *arr=x;
    }

    arr=tmparr;

    task21(arr, size);

    arr=tmparr;

    for(int i=0; i<size; i++, arr++)
    {
        fprintf(fout, "%d ", *arr);
    }

    free (tmparr);
    fclose(fin);
    fclose(fout);
    return 0;
}