#include"task29.h"

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
    scanf("%d", &x);
    task29(fin, fout, x);
    return 0;
}