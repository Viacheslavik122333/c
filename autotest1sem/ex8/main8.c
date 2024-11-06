#include "stdio.h"
#include "stdlib.h"

int cmp(const void *a, const void *b);
void fun(double *a, int M, double *b ,int N);

int main (void)
{
    int M=0;
    int N=0;
    double *ptrA;
    double *ptrB;
    double x;
    FILE*fina = fopen("ina.txt", "r");
    FILE*finb = fopen("inb.txt", "r");
    FILE*fout = fopen("output.txt", "w");
    if(!fina){return 0;}
    if(!finb){fclose(fina); return 0;}
    if(!fout){fclose(finb); fclose(fina); return 0;}
    while(fscanf(fina, "%lf", &x)==1){M++;}
    while(fscanf(finb, "%lf", &x)==1){N++;}
    if(N==0 || M==0){fclose(fout); fclose(finb); fclose(fina); return 0;}
    rewind(fina);rewind(finb);
    ptrA = (double*)malloc(M * sizeof(double));
    ptrB = (double*)malloc(N * sizeof(double));
    for(int i=0; i<M; i++){fscanf(fina, "%lf", &x); ptrA[i]=x;}
    for(int i=0; i<N; i++){fscanf(finb, "%lf", &x); ptrB[i]=x;}

    qsort(ptrA, M, sizeof(double), cmp);
    qsort(ptrB, N, sizeof(double), cmp);

    fun(ptrA, M, ptrB, N);

    for(int i=0; i<M; i++){fprintf(fout, "%lf ", ptrA[i]);}

    free(ptrA);
    free(ptrB);
    fclose(fout); 
    fclose(finb); 
    fclose(fina);
    return 0;
}

int cmp(const void *a, const void *b)
{
    const double *ad, *bd;
    ad = (const double*)a;
    bd = (const double*)b;

    if((*ad-*bd)>-1e-12){return 1;}
    else if((*ad-*bd)<1e-12){return -1;}
    else {return 0;}
}

void fun(double *a, int M, double *b ,int N)
{
    int min=(M<N)?M:N;
    for (int i=0; i<min; i++)
    {
        if((a[i]-b[i])<-1e-12)
        {
            a[i]=b[i];
        }
    }
}

