#include"task3.h"

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
    
    // if (fscanf(fin, "%d", &x) != 1)
    // {
    //     fprintf(stderr, "Empty file\n");
    //     fclose(fin);
    //     return -1;
    // }
    // rewind(fin);

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
    arr--;
    // arr = tmparr;

    //printf("%d\n", size);

    task3(arr, size); // функция

    arr = tmparr;
    for(int i=0; i<size; i++, arr++)
    {
        fprintf(fout, "%d ", *arr);
    }
    free (tmparr);
    
    
    return 0;
}