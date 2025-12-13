#include"stdlib.h"
#include"stdio.h"

int cmp(const void*a, const void*b);
int fun(double *a,double *b, int N);

int main(void)
{
    FILE* fina;
    FILE* finb;
    FILE* fout;
    int N=0, M=0, res=0;
    double x;
    double *a, *b;
    fina = fopen("ina.txt", "r");
    if(!fina){return -1;}
    finb = fopen("inb.txt", "r");
    if(!finb){fclose(fina); return -1;}
    fout = fopen("output.txt", "w");
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while(fscanf(finb, "%lf", &x)==1){N++;}
    while(fscanf(fina, "%lf", &x)==1){M++;}
    if(N<=2 || M<=2){fclose(fout); fclose(finb);fclose(fina); return -1;}
    a = (double*)malloc(N*sizeof(double));
    b = (double*)malloc(N*sizeof(double));
    rewind(fina);
    rewind(finb);
    for(int i=0; i<N; i++){fscanf(fina, "%lf", &x); a[i]=x;}
    for(int i=0; i<N; i++){fscanf(finb, "%lf", &x); b[i]=x;}
    qsort(a, N, sizeof(double), cmp);
    qsort(b, N, sizeof(double), cmp);
    res = fun(a, b, N);
    fprintf(fout, "%d", res);
    printf("%d", res);
    free(a);
    free(b);
    fclose(fout); 
    fclose(finb);
    fclose(fina);
    return 0;
}
int fun(double *a,double *b, int N)
{
    int res=0;
    int count=0;
    int tmp=0;
    if(a[0]>b[0])
    {
        for(int i=1; i<N; i++)
        {
            if(a[i]<b[i] && tmp==0)
            {
                tmp++;
                res=i;
                count++;
            }
            if((a[i]-b[i])>-1e-6 && (a[i]-b[i])<1e-6 && tmp==0)
            {
                tmp++;
                res=i;
                count++;
            }
            if(a[i]>b[i] && tmp!=0)
            {
                count++;
                break;
            }
        }
    }
    else
    {
        for(int i=1; i<N; i++)
        {
            if(a[i]>b[i] && tmp==0)
            {
                tmp++;
                res=i;
                count++;
            }
            if((a[i]-b[i])>-1e-6 && (a[i]-b[i])<1e-6 && tmp==0)
            {
                tmp++;
                res=i;
                count++;
            }
            if(a[i]<b[i] && tmp!=0)
            {
                count++;
                break;
            }
        }
    }
    
    if(count != 1 && count!=0)
    {
        res = -1;
    }
    return res;
}
int cmp(const void*a, const void*b)
{
    const double A = *(const double*)a;
    const double B = *(const double*)b;
    if(A>B){return 1;}
    else if(A<B){return -1;}
    else {return 0;}
}

