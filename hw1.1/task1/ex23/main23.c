#include"task23.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int res;
    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    res = task23(fin);
    fprintf(fout, "%d", res);
    return 0;
}