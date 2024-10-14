#include"stdio.h"
#include"stdlib.h"

void vvod(FILE *fin, int *arr, int k);
int max(int *arr, int k);
int min(int *arr, int k);
int task3(int *arra, int M, int maxA, int *arrb, int N, int minB);

int main (void)
{
    int M=0, N=0, x, maxA, minB, res;
    int *tmparra;
    int *arra;
    int *tmparrb;
    int *arrb;
    FILE *fina = fopen("ina.txt", "r");
    FILE *finb = fopen("inb.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(fina); fclose(finb); return -1;}
    while (fscanf(fina, "%d", &x)==1){M++;}
    while (fscanf(finb, "%d", &x)==1){N++;}
    rewind(fina);
    rewind(finb);
    if(M==0 || N==0){fclose(fina); fclose(finb); fclose(fout);return -1;}
    tmparra = (int*)malloc(M * sizeof(int));
    arra = tmparra;
    tmparrb = (int*)malloc(N * sizeof(int));
    arrb = tmparrb;
     
    vvod(fina, arra, M);
    vvod(finb, arrb, N);

    arra = tmparra;
    arrb = tmparrb;

    maxA = max(arra, M);
    minB = min(arrb, N);

    arra = tmparra;
    arrb = tmparrb;

    res = task3(arra, M, maxA, arrb, N, minB);

    fprintf(fout, "%d", res);
    free(tmparra);
    free(tmparrb);
    fclose(fina); fclose(finb); fclose(fout);
    return 0;
}

void vvod(FILE*fin, int *arr, int k)
{
    int x;
    for(int i=0; i<k; i++, arr++)
    {
        fscanf(fin, "%d", &x);
        *arr = x;
    }
}

int max(int *arr, int k)
{
    int res=-999;
    for(int i=0; i<k; i++, arr++)
    {
        if(res<*arr)
        {
            res = *arr;
        }
    }
    return res;
}
int min(int *arr, int k)
{
    int res=999;
    for(int i=0; i<k; i++, arr++)
    {
        if(res>*arr)
        {
            res = *arr;
        }
    }
    return res;
}

int task3(int *arra, int M, int maxA, int *arrb, int N, int minB)
{
    int res=0;
    for(int i=0; i<M; i++, arra++)
    {
        if(*arra>=minB)
        {
            res++;
        }
    }
    for(int i=0; i<N; i++, arrb++)
    {
        if(*arrb<=maxA)
        {
            res++;
        }
    }
    return res;
}


