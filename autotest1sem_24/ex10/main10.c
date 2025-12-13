#include"stdlib.h"
#include"stdio.h"

int cmp(const void*a, const void*b);
int fun(int *a, int M, int *b, int N);

int main(void)
{
    int M=0, N=0, x;
    int *a, *b;
    FILE* fina;
    FILE* finb;
    FILE* fout;
    fina = fopen("ina.txt", "r");
    if(!fina){return -1;}
    finb = fopen("inb.txt", "r");
    if(!finb){fclose(fina); return -1;}
    fout = fopen("output.txt", "w");
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while(fscanf(fina, "%d", &x)==1){M++;}
    while(fscanf(finb, "%d", &x)==1){N++;}
    if(M==0 || N==0){fclose(fout); fclose(finb);fclose(fina); return -1;}
    if(M==1 && N!=0){fprintf(fout, "YES"); fclose(fout); fclose(finb);fclose(fina); return 0;}
    a = (int*)malloc(M*sizeof(int));
    b = (int*)malloc(N*sizeof(int));
    rewind(fina);
    rewind(finb);
    for(int i=0; i<M; i++){fscanf(fina, "%d", &x); a[i]=x;}
    for(int i=0; i<N; i++){fscanf(finb, "%d", &x); b[i]=x;}
    qsort(a, M, sizeof(int), cmp);
    qsort(b, N, sizeof(int), cmp);
    if(fun(a, M, b, N)==1){fprintf(fout, "YES");}
    else{fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(fout); 
    fclose(finb);
    fclose(fina);
    return 0;
}
int fun(int *a, int M, int *b, int N)
{
    int count=0;
    for (int i=0; i<M-1; i++)
    {
        for (int j=0; j<N; j++)
        {
            if(a[i]<b[j])
            {
                if(a[i+1]<b[j] && count==0)
                {
                    return 0;
                }
                count++;
            }
        }
        count = 0;
    }
    return 1;
}
int cmp(const void*a, const void*b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b;
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}
