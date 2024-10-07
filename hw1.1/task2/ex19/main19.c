#include"task19.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int x, a, b; 
    int size=0;

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

    size++;

    scanf("%d", &x);

    int *tmparr = (int*)malloc(size * sizeof(int));
    int *arr = tmparr;

    for(int i=0; i<size-1; i++, arr++)
    {
        fscanf(fin, "%d", &b);
        *arr=b;
    }
    *(arr+1) = *arr + 1;

    arr=tmparr;

    task19(arr, size, x);

    arr=tmparr;
    
    for (int i=0; i<size; i++, arr++)
    {
        fprintf(fout, "%d ", *arr);
    }

    free (tmparr);
    fclose(fin);
    fclose(fout);
    return 0;
}
