#include"stdio.h"
#include"stdlib.h"

int cmp(const void*a, const void*b);
int fun(int *a, int n);

int main(void)
{
    FILE*fina = fopen("ina.txt", "r");
    FILE*finb = fopen("inb.txt", "r");
    FILE*fout = fopen("output.txt", "w");
    int n=0, m=0, x, *a, *b, res1, res2;
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(finb); fclose(fina); return -1;}
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
    if(res1>res2){fprintf(fout, "1"); printf("1");}
    else if(res1<res2){fprintf(fout, "-1"); printf("-1");}
    else {fprintf(fout, "0"); printf("0");}
    free(a); free(b); fclose(fout); fclose(finb); fclose(fina); 
    return 0;
}

int fun(int *a, int n)
{
    int res = 0, k=0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i] == a[j])
            {
                k++;
            }
        }
        if(res<=k){res=k;}
        k=0;
    }
    return res;
}


int cmp(const void*a, const void*b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b; 
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}