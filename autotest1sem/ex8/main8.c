#include "stdio.h"
#include "stdlib.h"

int cmp(const void *a, const void *b);
void fun(double *a, int M, double *b ,int N);

int main (void)
{
    int M=0, N=0;
    double *a, *b, x;
    FILE*fina = fopen("ina.txt", "r");
    FILE*finb = fopen("inb.txt", "r");
    FILE*fout = fopen("output.txt", "w");
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(finb); fclose(fina); return -1;}
    while(fscanf(fina, "%lf", &x)==1){M++;}
    while(fscanf(finb, "%lf", &x)==1){N++;}
    if(N==0 || M==0){fclose(fout); fclose(finb); fclose(fina); return -1;}
    rewind(fina);rewind(finb);
    a = (double*)malloc(M * sizeof(double));
    b = (double*)malloc(N * sizeof(double));
    for(int i=0; i<M; i++){fscanf(fina, "%lf", &x); a[i]=x;}
    for(int i=0; i<N; i++){fscanf(finb, "%lf", &x); b[i]=x;}
    qsort(a, M, sizeof(double), cmp);
    qsort(b, N, sizeof(double), cmp);
    fun(a, M, b, N);
    for(int i=0; i<M; i++){fprintf(fout, "%lf ", a[i]);}
    free(a);
    free(b);
    fclose(fout); 
    fclose(finb); 
    fclose(fina);
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

void fun(double *a, int M, double *b ,int N)
{
    int min=(M<N)?M:N;
    for (int i=0; i<min; i++)
    {
        if(a[i]<b[i])
        {
            a[i]=b[i];
        }
    }
}

