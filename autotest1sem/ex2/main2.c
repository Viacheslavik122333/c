#include"stdio.h"
#include"stdlib.h"

int task(double *a, int n, double *b, int m);
int cmp(const void*a, const void*b);

int main(void)
{
    int sizeA, sizeB;
    double *a, *b, x;
    FILE* finA = fopen("ina.txt", "r");
    FILE* finB = fopen("inb.txt", "r");
    FILE* fout = fopen("output.txt", "w");
    if(!finA){return -1;}
    if(!finB){fclose(finA); return -1;}
    if(!fout){fclose(finA);fclose(finB); return -1;}
    while(fscanf(finA, "%lf", &x)==1){sizeA++;}
    while(fscanf(finB, "%lf", &x)==1){sizeB++;}
    rewind(finA);
    rewind(finB);
    if(sizeA==0||sizeB==0){fclose(finA); fclose(finB); fclose(fout); return -1;}
    a = (double*)malloc(sizeA * sizeof(double));
    b = (double*)malloc(sizeB * sizeof(double));
    for(int i=0; i<sizeA; i++){fscanf(finA, "%lf", &x); a[i]=x;}
    for(int i=0; i<sizeB; i++){fscanf(finB, "%lf", &x); b[i]=x;}
    qsort(a, sizeA, sizeof(double), cmp);
    qsort(b, sizeB, sizeof(double), cmp);
    if(task(a, sizeA, b, sizeB)==1){fprintf(fout, "YES");printf("YES");}
    else{fprintf(fout, "NO");}
    free(a);
    free(b);
    fclose(finA); 
    fclose(finB); 
    fclose(fout);
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

