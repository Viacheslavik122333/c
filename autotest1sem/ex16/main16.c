#include"stdio.h"
#include"stdlib.h"

int cmp(const void*a, const void*b);
int fun(int *a, int n);
void fun2(int *a, int n, int *b, int m, FILE*f);
void sdvig(int *a, int n, int j);

int main(void)
{
    int n=0, m=0, x, *a, *b, res1, res2;
    FILE* fina;
    FILE* finb;
    FILE* fout;
    fina = fopen("ina.txt", "r");
    if(!fina){return -1;}
    finb = fopen("inb.txt", "r");
    if(!finb){fclose(fina); return -1;}
    fout = fopen("output.txt", "w");
    if(!fout){fclose(finb);fclose(fina); return -1;}
    
    while(fscanf(fina, "%d", &x)==1){n++;}
    while(fscanf(finb, "%d", &x)==1){m++;}
    if(n==0 || m==0){fclose(fout);fclose(finb); fclose(fina); return -1;}
    rewind(fina);rewind(finb);
    a = (int*)malloc(n*sizeof(int));
    b = (int*)malloc(m*sizeof(int));
    for(int i=0; i<n; i++){fscanf(fina, "%d", &x); a[i]=x;}
    for(int i=0; i<m; i++){fscanf(finb, "%d", &x); b[i]=x;}
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    res1 = fun(a, n);
    res2 = fun(b, m);
    fprintf(fout, "%d %d ", res1, res2);
    fun2(a, res1, b, res2, fout);
    free(a); free(b); fclose(fout); fclose(finb); fclose(fina); 
    return 0;
}
void fun2(int *a, int n, int *b, int m, FILE*f)
{
    int fl=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i]==b[j]){fl=0; break;}
        }
        if(fl==1){fprintf(f, "%d ", a[i]);}
        fl=1;
    }
}
int fun(int *a, int n)
{
    int tmp=n;
    int k=0;
    for(int i=0; i<tmp-1; i++)
    {
        if(a[i]==a[i+1])
        {
            sdvig(a, n, i+1);
            i--;
            k++;
            tmp--;
        }
    }
    return n-k;
}

int cmp(const void*a, const void*b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b; 
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}

void sdvig(int *a, int n, int j)
{
    for(int i=j; i<n-1; i++)
    {
        a[i] = a[i+1];
    }
}