#include "stdlib.h"
#include "stdio.h"

int cmp(const void*a, const void*b);
int task(double *a, int n, double *b, int m);

int main(void)
{
    int n, m;
    double *a, *b, x;
    FILE* fina;
    FILE* finb;
    FILE* fout;
    fina = fopen("ina.txt", "r");
    if(!fina){return -1;}
    finb = fopen("inb.txt", "r");
    if(!finb){fclose(fina); return -1;}
    fout = fopen("output.txt", "w");
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while(fscanf(fina, "%lf", &x)==1){n++;}
    while(fscanf(finb, "%lf", &x)==1){m++;}
    rewind(fina);
    rewind(finb);
    if(n==0||m==0){fclose(fina); fclose(finb); fclose(fout); return -1;}
    a = (double*)malloc(n * sizeof(double));
    b = (double*)malloc(m * sizeof(double));
    for(int i=0; i<n; i++){fscanf(fina, "%lf", &x); a[i]=x;}
    for(int i=0; i<m; i++){fscanf(finb, "%lf", &x); b[i]=x;}
    qsort(a, n, sizeof(double), cmp);
    qsort(b, m, sizeof(double), cmp);
    if(task(a, n, b, m)==1){fprintf(fout, "YES");printf("YES");}
    else{fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(fina); 
    fclose(finb); 
    fclose(fout);
    return 0;
}

int cmp(const void*a, const void*b)
{
    const double A = *(const double*)a;
    const double B = *(const double*)b;
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}

int task(double *a, int n, double *b, int m)
{
    double maxA = a[n-1];
    double maxB = b[m-1];
    double k = (n>m) ? n : m;
    for(int i = 0; i<k; i++)
    {
        if(i>=n)
        {
            if(maxA >= b[i])
            {
                return 0;
            }
        }
        else if(i>=m)
        {
            if(a[i] >= maxB)
            {
                return 0;
            }
        }
        else
        {
            if(a[i] >= b[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

