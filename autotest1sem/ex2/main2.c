#include"stdio.h"
#include"stdlib.h"

int task2(int *arra, int a, int *arrb, int b);
int size(FILE*f);
void rsort(int a[], int N);
void print(int *ptr, int N);
void swap(int *a, int *b);

int main(void)
{
    int x;
    FILE* fina = fopen("ina.txt", "r");
    FILE* finb = fopen("inb.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(fina);fclose(finb); return -1;}
    
    int sizea = size(fina);
    int sizeb = size(finb);
    if(sizea == 0 || sizeb == 0)
    {
        fclose(fina);fclose(finb); fclose(fout); return -1;
    }
    
    rewind(fina);
    rewind(finb);

    int *tmparra = (int*)malloc(sizea * sizeof(int));
    int *arra = tmparra;
    int *tmparrb = (int*)malloc(sizeb * sizeof(int));
    int *arrb = tmparrb;

    for(int i=0; i<sizea; i++)
    {
        fscanf(fina, "%d", &x);
        *arra = x;
        arra++;
    }
    for(int i=0; i<sizeb; i++)
    {
        fscanf(finb, "%d", &x);
        *arrb = x;
        arrb++;
    }

    arra = tmparra;    
    arrb = tmparrb;

    rsort(arra, sizea);
    rsort(arrb, sizeb);

    arra = tmparra;    
    arrb = tmparrb;

    if(task2(arra, sizea, arrb, sizeb)==1)
    {
        fprintf(fout, "YES");
    }
    else
    {
        fprintf(fout, "NO");
    }
    fclose(fina); fclose(finb); fclose(fout);
    free (tmparra);
    free (tmparrb);
    return 0;
}

int task2(int *arra, int a, int *arrb, int b)
{
    int min = (a<b) ? a : b;
    int count1=0, count2=0;
    for(int i=0; i<min; i++)
    {
        if(*arra < *arrb)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    int c = (count1>count2) ? 1 : -1;
    return c;
}

int size(FILE*f)
{
    int siz=0, x;
    while(fscanf(f, "%d", &x)==1)
    {
        siz++;
    }
    return siz;
}

void rsort(int a[], int N)
{
    for(int i=0; i<N; i++)
    {
        for(int j=i; j>0 && a[j]<a[j-1]; j++)
        {
            swap(&a[j], &a[j-1]);
        }
    }
}


void print(int *ptr, int N)
{
    for (int i=0; i<N; i++, ptr++)
    {
        printf("%d ", *ptr);
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

