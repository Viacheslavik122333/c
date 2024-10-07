#include"task11.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int a, size=0, x;

    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    while (fscanf(fin, "%d", &a) == 1)
    {
        size++;
    }
    rewind(fin);

    int *tmparr = (int*)malloc(size * sizeof(int));
    int *arr = tmparr;


    for(int i=0; i<size; i++, arr++)
    {
        fscanf(fin, "%d", &x);
        *arr=x;
    }
    arr=tmparr;

    task11(arr, size);

    arr = tmparr;

    for (int i=0; i<size; i++, arr++)
    {
        fprintf(fout, "%d ", *arr);
    }
    
    free (tmparr);
    fclose(fin);
    fclose(fout);
    return 0;
}