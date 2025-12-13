#include"stdio.h"
#include"stdlib.h"

int cmp(const void*a, const void*b);
int task7(int *arra, int *arrb, int min);

int main (void)
{
    int n=0, m=0, x, min;
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
    min = (n<=m) ? n : m;
    if(task7(a, b, min) ==1 || n==1 || m==1){fprintf(fout, "YES");}
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

int task7(int *a, int *b, int min)
{
    int tmp = a[0] - b[0];
    // printf("%d %d", min, tmp);
    for(int i=1; i<min; i++)
    {
        printf("%d %d %d\n", tmp, a[i], b[i]);
        if((a[i] - b[i]) != tmp)
        {
            return -1;
        }
    }
    return 1;
}