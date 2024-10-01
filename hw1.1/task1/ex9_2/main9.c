#include"task9.h"

int main (void) //все для любимой старосты 108 группы
{
    int x1, x2;
    int c1, c2, c3, b;
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    if (!fin)
    {
        fprintf(stderr, "Error opening data file\n");
        return -1;
    }
    
    if (!fscanf(fin, "%d %d", &x1, &x2))
    {
        fprintf(stderr, "Empty file\n");
        fclose(fin);
        return -1;
    }

    scanf("%d %d %d %d", &c1, &c2, &c3, &b);

    if(task9(fin, x1, x2, c1, c2, c3, b)==1)
    {
        fprintf(fout, "YES");
    }
    else 
    {
        fprintf(fout, "NO");
    }
    return 0;
}