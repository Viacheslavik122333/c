#include "stdio.h"
#include "stdlib.h"

void sort(int a[], int N);
int task4(int *arra, int M, int *arrb, int N);
void swap(int *a, int *b);

int main(void)
{
    int x, M=0, N=0;
    FILE * fina = fopen("ina.txt", "r");
    FILE * finb = fopen("inb.txt", "r");
    FILE * fout = fopen("output.txt", "w");
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(fina); fclose(finb); return -1;}
    while (fscanf(fina, "%d", &x)==1){M++;}
    while (fscanf(finb, "%d", &x)==1){N++;}

    rewind(fina);
    rewind(finb);

    if(M==0 || N==0)
    {fclose(fina); fclose(finb); fclose(fout); return -1;}
    if(M>N)
    {
        fprintf(fout, "NO");
        return 0;
    }

    int *tmparra = (int*)malloc(M * sizeof(int));
    int *arra=tmparra;
    int *tmparrb = (int*)malloc(N * sizeof(int));
    int *arrb=tmparrb;

    for(int i=0; i<M; i++, arra++)
    {
        fscanf(fina, "%d", &x);
        *arra=x;
    }
    for(int i=0; i<N; i++, arrb++)
    {
        fscanf(finb, "%d", &x);
        *arrb=x;
    }

    arra=tmparra;
    arrb=tmparrb;

    sort(arra, M);
    sort(arrb, N);
    
    arra=tmparra;
    arrb=tmparrb;

    if(task4(arra, M, arrb, N)==1)
    {
        fprintf(fout, "YES");
    }
    else
    {
        fprintf(fout, "NO");
    }

    free(tmparra);
    free(tmparrb);
    fclose(fina); 
    fclose(finb); 
    fclose(fout);
    return 0;
}

void sort(int a[], int N)
{
    for(int i=0; i<N; i++)
    {
        for(int j=i; j>0 && a[j-1]>a[j]; j--)
        {
            swap(&a[j-1], &a[j]);
        }
    }
}

int task4(int *arra, int M, int *arrb, int N)
{
    int k=0, res=1;
    while(*arra != *arrb)
    {
        arrb++;
        k++;
    }
    if(k == N)
    {
        res = 0;
        return res;
    }
    for(int i = 0; i<M; i++)
    {
        if(*arra != *arrb)
        {
            res = 0;
            return res;
        }
        arra++;
        arrb++;
    }
    return res;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}