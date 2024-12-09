#include"task1.h"

int main(void)
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    if(!fin){fprintf(stderr, "input -> error"); return -1;}
    if(!fout){fprintf(stderr, "output -> error"); fclose(fin); return -1;}
    fun(fin, fout);
    fclose(fin);
    fclose(fout);
    return 0;
}