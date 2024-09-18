#include"task3.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int x;
    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    // rewind(fin);

    // if (feof(fin))
    // {
    //     perror("sghksgh");
    //     printf("hfgksghkks");
    //     fclose(fin);
    //     return -1;
    // }
    
    if (fscanf(fin, "%d", &x) != 1)
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }
    rewind(fin);

    int quantity = task3(fin);
    fprintf(fout, "%d", quantity);
    return 0;
}