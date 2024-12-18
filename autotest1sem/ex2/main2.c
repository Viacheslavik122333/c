#include"stdio.h"
#include"stdlib.h"

int task(double *a, int n, double *b, int m);
int cmp(const void*a, const void*b);

int main(void)
{
    int n, m;
    double *a, *b, x;
    FILE* fina;
    FILE* finb;
    FILE* fout;
    fina = fopen("ina.txt", "r");
    if(!fina){return -1;}
    finb = fopen("inb.txt", "r");
    if(!finb){fclose(fina); return -1;}
    fout = fopen("output.txt", "w");
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while(fscanf(fina, "%lf", &x)==1){n++;}
    while(fscanf(finb, "%lf", &x)==1){m++;}
    rewind(fina);
    rewind(finb);
    if(n==0||m==0){fclose(fina); fclose(finb); fclose(fout); return -1;}
    a = (double*)malloc(n * sizeof(double));
    b = (double*)malloc(m * sizeof(double));
    for(int i=0; i<n; i++){fscanf(fina, "%lf", &x); a[i]=x;}
    for(int i=0; i<m; i++){fscanf(finb, "%lf", &x); b[i]=x;}
    qsort(a, n, sizeof(double), cmp);
    qsort(b, m, sizeof(double), cmp);
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
    const double A = *(const double*)a;
    const double B = *(const double*)b;
    if(A<B){return 1;}
    else if(A>B){return -1;}
    else {return 0;}
}

int task(double *a, int n, double *b, int m)
{
    int count1=0, count2=0, c;
    int min = (n<m) ? n : m;
    for(int i=0; i<min; i++)
    {
        if(a[i] < b[i])
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    c = (count1>count2) ? 1 : -1;
    return c;
}

