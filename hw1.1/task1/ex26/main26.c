#include"task26.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
   double sr;
    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    sr = task26(fin);
    fprintf(fout, "%.2lf", sr);
    return 0;
}