#include"task25.h"

int main (void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int dist;
    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }

    dist = task25(fin);
    fprintf(fout, "%d", dist);
    return 0;
}