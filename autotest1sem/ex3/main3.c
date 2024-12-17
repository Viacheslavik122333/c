#include"stdio.h"
#include"stdlib.h"

int cmp(const void*a, const void*b);
int task3(int *a, int n, int *b, int m);

int main (void)
{
    int n=0, m=0, x, res;
    int *a;
    int *b;
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
    // for(int i=0; i<n; i++){printf("%d ", a[i]);}
    // printf("\n");
    // for(int i=0; i<m; i++){printf("%d ", b[i]);}
    printf("\n");
    res = task3(a, n, b, m);
    fprintf(fout, "%d", res);
    printf("%d", res);
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

int task3(int *a, int n, int *b, int m)
{
    int minB = b[0];
    int maxA = a[n-1];
    int res=0;
    // printf("minB = %d\n", minB);
    // printf("maxA = %d\n", maxA);
    if(minB == maxA){return 1;}
    for(int i=0; i<n; i++)
    {
        if(a[i]>=minB)
        {
            if(i<n-1 && a[i]!=a[i+1]){res++;}
            if(i==n-1){res++;}
        }
    }
    printf("%d\n", res);
    for(int i=0; i<m; i++)
    {
        if(b[i]<maxA)
        {
            if(i<m-1 && b[i]!=b[i+1])
            {
                res++;
                for(int j=0; j<m; j++)
                {
                    if(b[i]==a[j]){res--; break;}
                }
            }
            if(i==m-1)
            {
                res++;
                for(int j=0; j<m; j++)
                {
                    if(b[i]==a[j]){res--; break;}
                }
            }
        }
    }
    return res;
} //A={1, 1, 2}  B={1, 2}


