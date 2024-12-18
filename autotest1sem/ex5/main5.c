#include"stdio.h"
#include"stdlib.h"

void task5(double *a, int n, double *b, int m, FILE*f);
int cmp(const void*a, const void*b);

int main(void)
{
    int n=0, m=0;
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
    task5(a, n, b, m, fout);
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

void task5(double *a, int n, double *b, int m, FILE*f)
{
    int min = (n<m) ? n : m;
    int count1=0, count2=0;
    printf("%d", min);
    for(int i=0; i<min; i++)
    {
        if(a[i]<b[i])
        {
            count1++;
        }
        if(a[i]>b[i])
        {
            count2++;
        }
    }
    fprintf(f, "%d %d", count1, count2);
}