#include"stdio.h"
#include"stdlib.h"

int task6(double *a, double *b, int min);
double mod(double a, double b);
int cmp(const void*a, const void*b);

int main(void)
{
    int n=0, m=0, min;
    double *a, *b, x;
    FILE* finA = fopen("ina.txt", "r");
    FILE* finB = fopen("inb.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    if(!finA){return -1;}
    if(!finB){fclose(finA); return -1;}
    if(!fout){fclose(finA);fclose(finB); return -1;}
    while(fscanf(finA, "%lf", &x)==1){n++;}
    while(fscanf(finB, "%lf", &x)==1){m++;}
    rewind(finA);
    rewind(finB);
    if(n==0 || m==0){fclose(finA); fclose(finB); fclose(fout); return -1;}
    if(n==1 || m==1){fprintf(fout, "YES"); fclose(finA); fclose(finB); fclose(fout); return -1;}
    a = (double*)malloc(n * sizeof(double));
    b = (double*)malloc(m * sizeof(double));
    for(int i=0; i<n; i++){fscanf(finA, "%lf", &x); a[i]=x;}
    for(int i=0; i<m; i++){fscanf(finB, "%lf", &x); b[i]=x;}
    qsort(a, n, sizeof(double), cmp);
    qsort(b, m, sizeof(double), cmp);
    min = (n<=m) ? n : m;
    if(task6(a, b, min) == 1){fprintf(fout, "YES");}
    else{fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(finA); 
    fclose(finB); 
    fclose(fout);
    return 0;
}

int cmp(const void*a, const void*b)
{
    const double A = *(const double*)a;
    const double B = *(const double*)b;
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}

int task6(double *a, double *b, int min)
{
    double tmp = mod(a[0], b[0]);
    for(int i=1; i<min; i++)
    {
        if(mod(a[i], b[i]) > tmp)
        {
            return -1;
        }
        tmp = mod(a[i], b[i]);
    }
    return 1;
}

double mod(double a, double b)
{
    double res = a - b;
    if(res < 0){res = -res;}
    return res;
}