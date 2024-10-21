#include"task1.h"

void Simple_sorting_by_exchanges_1(double a[], int k)
{
    double tmp;
    for(int i=1; i<k; i++)
    {
        for(int j=i; j>0 && (a[j-1]-a[j])>1e-10; j--)
        {
            tmp = a[j-1];
            a[j-1] = a[j];
            a[j] = tmp;
        }
    }
}

int cmp_2(double a, double b)
{
    if((a-b)<-1e-6){return -1;}
    if((a-b)>1e-6){return 1;}
    return 0;
}
void Simple_sorting_by_exchanges_2(double a[], size_t size, int (*cmp_2)(double, double))
{
    double tmp;
    int k = size;
    for(int i=1; i<k; i++)
    {
        for(int j=i; j>0 && cmp_2(a[j-1], a[j])==1; j--)
        {
            tmp = a[j-1];
            a[j-1] = a[j];
            a[j] = tmp;
        }
    }
}


int cmp_3(const void *a, const void *b)
{
    const double *ad, *bd;
    
    ad = (const double*)a;
    bd = (const double*)b;
   
    if ((*ad - *bd)<-1e-12) {return -1;}   
    else if ((*ad - *bd)>1e-12) {return 1;}   
    else {return 0;}   
}
void swap(void * x, void * y, size_t size)	
{		      
    char *a = x;
    char *b = y;
    char tmp;					      
    do								      
    {								      
        tmp = *a;						      
        *a++ = *b;						      
        *b++ = tmp;						      
    } while (--size > 0);	
}
void Simple_sorting_by_exchanges_3(void * a, size_t size, size_t elem_length, int (*cmp_3)(const void *, const void *))
{
    char *ptr = a;
    void * begin = ptr;
    int k = size;
    for(int i=1; i<k; i++)
    {
        ptr+=(elem_length*i);
        for(size_t j=i; j>0 && cmp_3((ptr-elem_length), ptr)==1; j--, ptr-=elem_length)
        {
            swap((ptr-elem_length), ptr, elem_length);
        }
        ptr = begin;
    }
}


int cmp_qsort(const void *a, const void *b)
{
    const double *ad, *bd;
    
    ad = (const double*)a;
    bd = (const double*)b;
   
    if ((*ad - *bd)<-1e-12) {return -1;}   
    else if ((*ad - *bd)>1e-12) {return 1;}   
    else {return 0;}   
}



