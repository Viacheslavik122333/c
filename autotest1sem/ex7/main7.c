#include"stdio.h"
#include"stdlib.h"

void sort(int a[], int k);
void swap(int *a, int *b);
int task7(int *arra, int *arrb, int min);

int main(void)
{
    int x, y, M=0, N=0, min;
    int *tmparra;
    int *arra;
    int *tmparrb;
    int *arrb;
    FILE*fina = fopen("ina.txt", "r");
    FILE*finb = fopen("inb.txt", "r");
    FILE*fout = fopen("output.txt", "w");
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(finb); fclose(fina); return -1;}
    while(fscanf(fina, "%d", &x)==1){M++;}
    while(fscanf(finb, "%d", &x)==1){N++;}
    rewind(fina);
    rewind(finb);
    if(M == 0 || N==0){fclose(fout); fclose(finb); fclose(fina); return -1;}
    tmparra = (int*)malloc(M * sizeof(int));
    tmparrb = (int*)malloc(N * sizeof(int));
    arra = tmparra;
    arrb = tmparrb;
    min = (M<=N) ? M : N;
    for(int i=0; i<M; i++, arra++){fscanf(fina, "%d", &x); *arra = x;}
    for(int i=0; i<N; i++, arrb++){fscanf(finb, "%d", &y); *arrb = y;}
    arra = tmparra;
    arrb = tmparrb;
    sort(arra, M);
    sort(arrb, N);
    arra = tmparra;
    arrb = tmparrb;
    if(task7(arra, arrb, min) || N==1 || M==1){fprintf(fout, "YES");}
    else{fprintf(fout, "NO");}
    free(tmparra);
    free(tmparrb);
    fclose(fout); 
    fclose(finb); 
    fclose(fina); 
    return 0;
}

void sort(int a[], int k)
{
    for(int i = 1; i<k; i++)
    {
        for(int j = i; j>=0 && a[j-1]>a[j]; j--)
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

int task7(int *arra, int *arrb, int min)
{
    int tmp = *arra - *arrb;
    int count=0, res=0;
    for(int i=0; i<min; i++, arra++, arrb++)
    {
        if((*arra - *arrb) == tmp)
        {
            count++;
        }
    }
    if(count == min){res = 1;}
    return res;
}