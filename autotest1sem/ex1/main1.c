#include "stdlib.h"
#include "stdio.h"

int cmp(const void*a, const void*b);
int task(double *a, int n, double *b, int m);

int main(void)
{
    int n, m;
    double *a, *b, x;
    FILE* finA = fopen("ina.txt", "r");
    FILE* finB = fopen("inb.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    if(!finA){return -1;}
    if(!finB){fclose(finA); return -1;}
    if(!fout){fclose(finA);fclose(finB); return -1;}
    while(fscanf(finA, "%lf", &x)==1){n++;}
    while(fscanf(finB, "%lf", &x)==1){m++;}
    rewind(finA);
    rewind(finB);
    if(n==0||m==0){fclose(finA); fclose(finB); fclose(fout); return -1;}
    a = (double*)malloc(n * sizeof(double));
    b = (double*)malloc(m * sizeof(double));
    for(int i=0; i<n; i++){fscanf(finA, "%lf", &x); a[i]=x;}
    for(int i=0; i<m; i++){fscanf(finB, "%lf", &x); b[i]=x;}
    qsort(a, n, sizeof(double), cmp);
    qsort(b, m, sizeof(double), cmp);
    if(task(a, n, b, m)==1){fprintf(fout, "YES");printf("YES");}
    else{fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(finA); 
    fclose(finB); 
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

