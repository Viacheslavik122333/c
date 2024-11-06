#include"task1.h"
// сортировка перестановка максимума

void Simple_sorting_by_exchanges_1(double a[], const size_t size) // 1 реализация 
{
    int count=0;
    double max;
    int imax=0;
    for(int i=size-1; i>=0; i--)
    {
        max = a[i];
        for (int j = 0; j<=i; j++)
        {
            if((a[j]-max)>1e-12)
            {
                count++;
                max = a[j];
                imax = j;
            }
        }
        if(count>0)
        {
            a[imax] = a[i];
            a[i]=max;
        }
        count =0;
    }
}

void Simple_sorting_by_exchanges_2(double a[], const size_t size, int (*cmp_2)(double, double)) // 2 реализвция
{
    int count=0;
    double max;
    int imax=0;
    for(int i=size-1; i>=0; i--)
    {
        max = a[i];
        for (int j = 0; j<=i; j++)
        {
            if(cmp_2(a[j], max)==1)
            {
                count++;
                max = a[j];
                imax = j;
            }
        }
        if(count>0)
        {
            a[imax] = a[i];
            a[i]=max;
        }
        count =0;
    }
}
int cmp_2(double a, double b) // фунция сравнения для 2 реализации
{
    if((a-b)>1e-6){return 1;}
    if((a-b)<-1e-6){return -1;}
    return 0;
}



void Simple_sorting_by_exchanges_3(void * a, const size_t size, const size_t elem_length, int (*cmp_3)(const void *, const void *)) // 3 реализация 
{
    char *ptr = a;
    void * begin = ptr;
    char tmpptr[elem_length]; 
    int count=0;
    int k = elem_length;
    int imax=0;
    for(int i=size-1; i>=0; i--)
    {
        ptr = begin;
        ptr += i*elem_length;
        for (int l=0; l<k; l++, ptr++){tmpptr[l]=*ptr;}

        ptr = begin;
        for (int j = 0; j<=i; j++, ptr+=elem_length)
        {
            if(cmp_3(ptr, tmpptr)==1)
            {
                count++;

                for (int t=0; t<k; t++, ptr++){tmpptr[t]=*ptr;}
                ptr-=elem_length;
                imax = j;
            }
        }
        if(count>0)
        {
            ptr = begin;
            swap(ptr+imax*elem_length, ptr+i*elem_length,elem_length);
        }
        count =0;
    }
}
int cmp_3(const void *a, const void *b) // фунция сравнения для 3 реализации
{
    const double *ad, *bd;
    
    ad = (const double*)a;
    bd = (const double*)b;
   
    if ((*ad - *bd)<-1e-12) {return -1;}   
    else if ((*ad - *bd)>1e-12) {return 1;}   
    else {return 0;}   
}
void swap(void * x, void * y, size_t size) // функия обмена элементов (типа void) для 3 реализации
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


int cmp_qsort(const void *a, const void *b) // фунция сравнения для быстрой сортировки
{
    const double *ad, *bd;
    
    ad = (const double*)a;
    bd = (const double*)b;
   
    if ((*ad - *bd)<-1e-12) {return -1;}   
    else if ((*ad - *bd)>1e-12) {return 1;}   
    else {return 0;}   
}



