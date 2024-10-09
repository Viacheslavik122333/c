#include"task17.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int x, a, b; 
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

    scanf("%d %d", &a, &b);

    if(task17(arr, size, a, b))
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