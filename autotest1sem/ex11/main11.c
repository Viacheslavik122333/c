#include"stdlib.h"
#include"stdio.h"

int cmp(const void*a, const void*b);
int fun(double *a,double *b, int N);

int main(void)
{
    FILE* fina = fopen("ina.txt", "r");
    FILE* finb = fopen("inb.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    int N=0;
    double x;
    double *ptra, *ptrb;
    if(!fina){return -1;}
    if(!finb){fclose(fina); return -1;}
    if(!fout){fclose(finb);fclose(fina); return -1;}
    while(fscanf(finb, "%lf", &x)==1){N++;}
    if(N<=2){fclose(fout); fclose(finb);fclose(fina); return -1;}
    ptra = (double*)malloc(N*sizeof(double));
    ptrb = (double*)malloc(N*sizeof(double));
    rewind(fina);
    rewind(finb);
    for(int i=0; i<N; i++){fscanf(fina, "%lf", &x); ptra[i]=x;}
    for(int i=0; i<N; i++){fscanf(finb, "%lf", &x); ptrb[i]=x;}
    qsort(ptra, N, sizeof(double), cmp);
    qsort(ptrb, N, sizeof(double), cmp);
    fprintf(fout, "%d", fun(ptra, ptrb, N));
    free(ptra);
    free(ptrb);
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
    if((a[0]- b[0])>1e-6)
    {
        for(int i=1; i<N; i++)
        {
            if((a[i]-b[i])<-1e-6 && tmp==0)
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
            if((a[i]-b[i])>1e-6 && tmp!=0)
            {
                count++;
                break;
            }
        }
    }
    else if ((a[0]- b[0])<-1e-6)
    {
        for(int i=1; i<N; i++)
        {
            if((a[i]-b[i])>1e-6 && tmp==0)
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
            if((a[i]-b[i])<-1e-6 && tmp!=0)
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
    if((A-B)>1e-6){return 1;}
    else if((A-B)<-1e-6){return -1;}
    else {return 0;}
}

