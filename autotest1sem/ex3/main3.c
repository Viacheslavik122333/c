#include"stdio.h"
#include"stdlib.h"

int fun(int *a, int n, int *b, int m, int j);
int cmp(const void*a, const void*b);
int task(int *a, int n, int *b, int m);

int main (void)
{
    int n=0, m=0, x, res;
    int *a, *b;
    FILE* fina;
    FILE* finb;
    FILE* fout;
    fina = fopen("ina.txt", "r");
    if(!fina){return -1;}
    finb = fopen("inb.txt", "r");
    if(!finb){fclose(fina); return -1;}
    fout = fopen("output.txt", "w");
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while (fscanf(fina, "%d", &x)==1){n++;}
    while (fscanf(finb, "%d", &x)==1){m++;}
    rewind(fina);
    rewind(finb);
    if(n==0 || m==0){fclose(fina); fclose(finb); fclose(fout);return -1;}
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(m * sizeof(int));
    for(int i=0; i<n; i++){fscanf(fina, "%d", &x); a[i] = x;}
    for(int i=0; i<m; i++){fscanf(finb, "%d", &x); b[i] = x;}
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    res = task(a, n, b, m);
    fprintf(fout, "%d", res);
    free(a);
    free(b);
    fclose(fina); 
    fclose(finb); 
    fclose(fout);
    return 0;
}

int cmp(const void*a, const void*b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b;
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}

int task(int *a, int n, int *b, int m)
{
    int res=0;
    for (int i=b[0]; i<=a[n-1]; i++)
    {
        res += fun(a, n, b, m, i);
    }
    return res;
}

int fun(int *a, int n, int *b, int m, int j)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==j){return 1;}
    }
    for(int i=0; i<m; i++)
    {
        if(b[i]==j){return 1;}
    }
    return 0;
}


