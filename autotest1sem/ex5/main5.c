#include"stdio.h"
#include"stdlib.h"


void rsort(int a[], int N);
void swap(int *a, int *b);
void task5(int *arra, int *arrb, int k);

int main(void)
{
    int x, M=0, N=0, min=0;
    int *tmparra;
    int *arra;
    int *tmparrb;
    int *arrb;

    FILE*fina = fopen("ina.txt", "r");
    FILE*finb = fopen("inb.txt", "r");
    FILE*fout = fopen("output.txt", "w");
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while (fscanf(fina, "%d", &x)==1){M++;}
    while (fscanf(finb, "%d", &x)==1){N++;}

    rewind(fina);
    rewind(finb);

    tmparra = (int*)malloc(M * sizeof(int));
    arra=tmparra;
    tmparrb = (int*)malloc(N * sizeof(int));
    arrb=tmparrb;

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

    rsort(arra, M);
    rsort(arrb, N);

    arra=tmparra;
    arrb=tmparrb;

    min = (M<=N) ? M : N;

    task5(arra, arrb, min);

    arra=tmparra;
    arrb=tmparrb;

    fprintf(fout, "%d %d", *arra, *arrb);

    free(tmparra);
    free(tmparrb);
    fclose(fina); 
    fclose(finb); 
    fclose(fout);
    return 0;
}

void rsort(int a[], int N)
{
    for(int i=1; i<N; i++)
    {
        for(int j=i; j>0 && a[j-1]<a[j]; j--)
        {
            swap(&a[j-1], &a[j]);
        }
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void task5(int *ptr1, int *ptr2, int k)
{
    int count1=0, count2=0; 
    int *arra=ptr1;
    int *arrb=ptr2;
    for(int i=0; i<k; i++, arra++, arrb++)
    {
        if(*arra<*arrb)
        {
            count1++;
        }
        if(*arra>*arrb)
        {
            count2++;
        }
    }
    *ptr1 = count1;
    *ptr2 = count2;
}