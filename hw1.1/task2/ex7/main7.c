#include"task7.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int a, size=0, x, res;

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

    // printf("%d ", size1);
    // printf("%d\n", size2);

    int *tmparr = (int*)malloc(size * sizeof(int));
    int *arr = tmparr;


    for(int i=0; i<size; i++, arr++)
    {
        fscanf(fin, "%d", &x);
        *arr=x;
    }
    arr=tmparr;

    res = task7(arr, size);

    fprintf(fout, "%d", res);

    free (tmparr);
    return 0;
}