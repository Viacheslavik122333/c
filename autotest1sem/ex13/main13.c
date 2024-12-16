#include"stdio.h"
#include"stdlib.h"

int fun (int *a, int n, int *b, int m);
int cmp(const void *a, const void *b);

int main(void)
{
    FILE*fina=fopen("ina.txt", "r");
    FILE*finb=fopen("inb.txt", "r");
    FILE*fout=fopen("output.txt", "w");
    int n=0, m=0, res;
    int x;
    int *a, *b;
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(finb); fclose(fina); return -1;}
    while(fscanf(fina, "%d", &x)==1){n++;}
    while(fscanf(finb, "%d", &x)==1){m++;}
    if(n==0 || m==0){fclose(fout); fclose(finb); fclose(fina); return -1;}
    rewind(fina);rewind(finb);
    a = (int*)malloc(n*sizeof(int));
    b = (int*)malloc(m*sizeof(int));
    for(int i=0; i<n; i++){fscanf(fina, "%d", &x); a[i]=x;}
    for(int i=0; i<m; i++){fscanf(finb, "%d", &x); b[i]=x;}
    qsort(a, n, sizeof(int), cmp);
    qsort(b, n, sizeof(int), cmp);
    res = fun(a, n, b, m);
    if(res==1){fprintf(fout, "YES");}
    else {fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(fout); 
    fclose(finb); 
    fclose(fina);
    return 1;
}

int cmp(const void *a, const void *b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b;
    if(B<A){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}

int fun (int *a, int n, int *b, int m)
{
    int min = (a[0]<b[0]) ? a[0] : b[0];
    int j1=0, j2=0, fl1=0, fl2=0;
    for(int i = min; i<n+m+min; i++)
    {
        if(a[j1]==i){j1++; fl1=1;}
        if(b[j2]==i){j2++; fl2=1;}
        if(fl1==1 && fl2==1){return -1;}
        if(fl1==0 && fl2==0){return -1;}
        fl1=0; fl2=0;
    }
    return 1;
}
