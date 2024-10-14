#include "stdlib.h"
#include "stdio.h"

int size(FILE* fin);
void sort(int a[], int N);
int task(int *arrA, int M, int *arrB, int N);
void swap(int *a, int *b);
int max(int *ptr, int N);

int main(void)
{
    int a=0, b=4;
    int sizeA, sizeB;
    int *tmparrA;
    int *arrA;
    int *tmparrB;
    int *arrB;
    FILE* finA = fopen("ina.txt", "r");
    FILE* finB = fopen("inb.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    if(!finA){return -1;}
    if(!finB){fclose(finA); return -1;}
    if(!fout){fclose(finA);fclose(finB); return -1;}
    sizeA = size(finA);
    sizeB = size(finB);
    rewind(finA);
    rewind(finB);
    if(sizeA == 0 || sizeB == 0)
    {
       fclose(finA); fclose(finB); fclose(fout); return -1;
    }

    tmparrA = (int*)malloc(sizeA * sizeof(int));
    arrA = tmparrA;

    tmparrB = (int*)malloc(sizeB * sizeof(int));
    arrB = tmparrB;

    for(int i=0; i<sizeA; i++)
    {
        fscanf(finA, "%d", &b);
        *arrA=b;
        arrA++;
    }
    for(int i=0; i<sizeB; i++)
    {
        fscanf(finB, "%d", &a);
        *arrB=a;
        arrB++;
    }

    arrA = tmparrA;
    arrB = tmparrB;

    for(int i=0; i<sizeA; i++, arrA++)
    {
        printf("%d ", *arrA);
    }
    printf("\n");
    for(int i=0; i<sizeB; i++, arrB++)
    {
        printf("%d ", *arrB);
    }

    arrA = tmparrA;
    arrB = tmparrB;

    sort(arrA, sizeA);
    sort(arrB, sizeB);

    arrA = tmparrA;
    arrB = tmparrB;

    if(task(arrA, sizeA, arrB, sizeB))
    {
        fprintf(fout, "YES");
    }
    else
    {
        fprintf(fout, "NO");
    }

    free(tmparrA);
    free(tmparrB);
    fclose(finA); 
    fclose(finB); 
    fclose(fout);
}

int size(FILE*fin)
{
    int a, count=0;
    while(fscanf(fin, "%d", &a)==1)
    {
        count++;
    }
    return count;
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

int task(int *arrA, int M, int *arrB, int N)
{
    int maxA = max(arrA, M);
    int maxB = max(arrB, N);
    int K = (M>N) ? M : N;

    for(int i = 0; i<K; i++, arrA++, arrB++)
    {
        if(i>M)
        {
            if(maxA >= *arrB)
            {
                return 0;
            }
        }
        else if(i>N)
        {
            if(*arrA >= maxB)
            {
                return 0;
            }
        }
        else
        {
            if(*arrA >= *arrB)
            {
                return 0;
            }
        }
    }
    return 1;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

int max(int *ptr, int N)
{
    int max=0;
    for(int i=0; i<N; i++)
    {
        if(max<*ptr)
        {
            max=*ptr;
        }
    }
    return max;
}
