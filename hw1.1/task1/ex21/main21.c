#include"task21.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int quantity;
    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    quantity = task21(fin);
    fprintf(fout, "%d", quantity);
    return 0;
}