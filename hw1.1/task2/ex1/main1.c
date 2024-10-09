#include"task1.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    int a, size=0, x;
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
    arr = tmparr;

    if(task1(arr, size))
    {
        printf("Симметричны\n");
    }
    else
    {
        printf("Не симметричный\n");
    }
    free (tmparr);
    fclose(fin);
    return 0;
}