#include "stdio.h"
#include "stdlib.h"

int task(int *arra, int M, int *arrb, int N);
int cmp(const void*a, const void*b);

int main (void)
{
    int n=0, m=0, x;
    int *a, *b;
    FILE *fina = fopen("ina.txt", "r");
    FILE *finb = fopen("inb.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(fina); fclose(finb); return -1;}
    while (fscanf(fina, "%d", &x)==1){n++;}
    while (fscanf(finb, "%d", &x)==1){m++;}
    rewind(fina);
    rewind(finb);
    if(n==0 || m==0){fclose(fina); fclose(finb); fclose(fout);return -1;}
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(m * sizeof(int));
    for(int i=0; i<n; i++){fscanf(fina, "%d", &x); a[i] = x;}
    for(int i=0; i<m; i++){fscanf(finb, "%d", &x); b[i] = x;}
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);
    if(task(a, n, b, m)==1){fprintf(fout, "YES");printf("YES");}
    else{fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(fina); 
    fclose(finb); 
    fclose(fout);
    return 0;
}

int cmp(const void*a, const void*b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b;
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}

int task(int *a, int n, int *b, int m)
{
    int res=1, k=0;
    if(n>m){return -1;}
    for(int g=0; g<m; g++)
    {
        if(a[0]==b[g])
        {
            printf("%d %d\n", g, n);
            for(int i = g; i<n+g; i++, k++)
            {
                if(a[k] != b[i])
                {
                    res = 0;
                    break;
                }
            }
        }
    }
    return res;
}
