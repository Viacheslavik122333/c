#include"stdio.h"
#include"stdlib.h"

int cmp(const void*a, const void*b);
int fun(double *a, double *b, int n);

int main (void)
{
    FILE*fina;
    FILE*finb;
    FILE*fout;
    double x;
    int n=0, m=0, res;
    double *a, *b;
    fina = fopen("ina.txt", "r");
    if(!fina){return -1;}
    finb = fopen("inb.txt", "r");
    if(!finb){fclose(fina); return -1;}
    fout = fopen("output.txt", "w");
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while(fscanf(fina, "%lf", &x)==1){n++;}
    while(fscanf(finb, "%lf", &x)==1){m++;}
    if(m!=n){fclose(fout); fclose(finb); fclose(fina); return -1;}
    if(n==0){fclose(fout); fclose(finb); fclose(fina); return -1;}
    a = (double*)malloc(n*sizeof(double));
    b = (double*)malloc(n*sizeof(double));
    rewind (fina); rewind(finb);
    for(int i=0; i<n; i++){fscanf(fina, "%lf", &x); a[i] = x;}
    for(int i=0; i<n; i++){fscanf(finb, "%lf", &x); b[i] = x;}
    qsort(a, n, sizeof(double), cmp);
    qsort(b, n, sizeof(double), cmp);
    res = fun(a, b, n);
    if(res==1){fprintf(fout, "YES");}
    else{fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(fout); 
    fclose(finb); 
    fclose(fina); 
    return -1;
}

int cmp(const void*a, const void*b)
{
    const double A = *(const double*)a;
    const double B = *(const double*)b;
    if((B-A>1e-6)){return 1;}
    else if ((A-B>1e-6)){return -1;}
    else {return 0;}
}

int fun(double *a, double *b, int n)
{
    int fl1=0, fl2=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>b[i])
        {
            fl1 = 1;
        }
        else if(b[i]>a[i])
        {
            fl1 = -1;
        }
        else
        {
            return -1;
        }
        if(fl1==fl2){return -1;}
        fl2=fl1;
    }
    return 1;
}