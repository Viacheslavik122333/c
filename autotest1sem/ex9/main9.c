#include "stdio.h"
#include "stdlib.h"

int cmp(const void *a, const void *b);
int fun(int *a, int *b ,int M);
void print(int *a, int *b, int M);

int main (void)
{
    int M=0;
    int res1;
    int res2;
    int *ptrA;
    int *ptrB;
    int x;
    FILE*fina = fopen("ina.txt", "r");
    FILE*finb = fopen("inb.txt", "r");
    FILE*fout = fopen("output.txt", "w");
    if(!fina){return 0;}
    if(!finb){fclose(fina); return 0;}
    if(!fout){fclose(finb); fclose(fina); return 0;}
    while(fscanf(fina, "%d", &x)==1){M++;}
    if(M==0){fclose(fout); fclose(finb); fclose(fina); return 0;}
    if(M==1){fprintf(fout, "YES YES"); fclose(fout); fclose(finb); fclose(fina); return 0;}
    rewind(fina);
    ptrA = (int*)malloc(M * sizeof(int));
    ptrB = (int*)malloc(M * sizeof(int));
    for(int i=0; i<M; i++){fscanf(fina, "%d", &x); ptrA[i]=x;}
    for(int i=0; i<M; i++){fscanf(finb, "%d", &x); ptrB[i]=x;}

    res1 = fun(ptrA, ptrB, M);
    
    qsort(ptrA, M, sizeof(int), cmp);
    qsort(ptrB, M, sizeof(int), cmp);

    res2 = fun(ptrA, ptrB, M);

    if(res1 == 1){fprintf(fout, "YES ");}
    else {fprintf(fout, "NO ");}
    if(res2 == 1){fprintf(fout, "YES");}
    else {fprintf(fout, "NO");}
    free(ptrA);
    free(ptrB);
    fclose(fout); 
    fclose(finb); 
    fclose(fina); 
    return 0;
}

int cmp(const void *a, const void *b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b;
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else{return 0;}
}

int fun(int *a, int *b ,int M)
{
    int *ptr;
    int c;
    ptr = (int*)malloc(M*sizeof(int));
    for (int i=0; i<M; i++)
    {
        c=a[i]-b[i];
        ptr[i]=a[i]-b[i];
        for(int j=0; j<i; j++)
        {
            if(ptr[j] == c){return -1;}
        }
    }
    free(ptr);
    return 1;
}
void print(int *a, int *b, int M)
{
    for (int i=0; i<M; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i=0; i<M; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}