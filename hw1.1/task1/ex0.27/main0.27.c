#include"task0.27.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    int size=0, a;
    double res=0;
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
        fscanf(fin, "%d", &a);
        *arr=a;
    }

    arr=tmparr;

    res = task27(arr, size);
    printf("%.2lf", res);
    return 0;
}