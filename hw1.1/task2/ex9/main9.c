#include"task9.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int a, size=0, x, size2=0;
    int *tmparr;
    int *arr;

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

    tmparr = (int*)malloc(size * sizeof(int));
    arr = tmparr;


    for(int i=0; i<size; i++, arr++)
    {
        fscanf(fin, "%d", &x);
        *arr=x;
    }
    arr=tmparr;

    size2 = task9(arr, size);

    arr = tmparr;

    for (int i=0; i<size2; i++, arr++)
    {
        fprintf(fout, "%d ", *arr);
    }
    fprintf(fout, "\nКол-во элементов = %d", size2);

    free (tmparr);
    fclose(fin);
    fclose(fout);
    return 0;
}