#include"task17.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int x;
    if (!fin) //проверка на присутствие файла
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    if (fscanf(fin, "%d", &x) != 1) //проверка на пустоту файла
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }
    rewind(fin);

    int quantity = task17(fin);
    fprintf(fout, "%d", quantity);
    return 0;
}