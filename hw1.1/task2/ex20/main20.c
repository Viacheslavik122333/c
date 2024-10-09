#include"task20.h"

int main (void)
{
    FILE* fin1 = fopen("input1.txt", "r");
    FILE* fin2 = fopen("input2.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int a, b, size1=0, size2=0, x, y;
    int *tmparr1;
    int *tmparr2;
    int *tmparr3;
    int *arr1;
    int *arr2;
    int *arr3;

    if (!fin1 && !fin2)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    while (fscanf(fin1, "%d", &a) == 1)
    {
        size1++;
    }
    rewind(fin1);
    while (fscanf(fin2, "%d", &b) == 1)
    {
        size2++;
    }
    rewind(fin2);

    tmparr1 = (int*)malloc(size1 * sizeof(int));
    arr1 = tmparr1;

    tmparr2 = (int*)malloc(size2 * sizeof(int));
    arr2 = tmparr2;

    tmparr3 = (int*)malloc((size1+size2)*sizeof(int));
    arr3 = tmparr3;

    for(int i=0; i<size1; i++, arr1++)
    {
        fscanf(fin1, "%d", &x);
        *arr1=x;
    }

    for(int i=0; i<size2; i++, arr2++)
    {
        fscanf(fin2, "%d", &y);
        *arr2=y;
    }

    arr1=tmparr1;
    arr2 = tmparr2;

    task20(arr1, size1, arr2, size2, arr3);
    
    for(int i=0; i<size1+size2; i++, arr3++)
    {
        fprintf(fout, "%d ", *arr3);
    }

    free (tmparr1);
    free (tmparr2);
    free (tmparr3);
    fclose(fin1);
    fclose(fin2);
    fclose(fout);
    return 0;
}