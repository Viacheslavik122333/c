#include"task3.h"
// 3) сортировка просеиванием (нисходящяя пузырьковая)

void Sieving_sorting_1(double a[], const size_t size) // 1 реализация
{
    double tmp;
    int k = size;
    for(int i=1; i<k; i++)
    {
        for(int j=i; j>0 && (a[j]-a[j-1])>1e-10; j--)
        {
            tmp = a[j-1];
            a[j-1] = a[j];
            a[j] = tmp;
        }
    }
}

void Sieving_sorting_2(double a[], size_t size, int (*cmp_2)(double, double)) // 2 реализация
{
    double tmp;
    int k = size;
    for(int i=1; i<k; i++)
    {
        for(int j=i; j>0 && cmp_2(a[j], a[j-1])==1; j--)
        {
            tmp = a[j-1];
            a[j-1] = a[j];
            a[j] = tmp;
        }
    }
}
int cmp_2(double a, double b) // фунция сравнения для 2 реализации
{
    if((a-b)<-1e-6){return -1;}
    if((a-b)>1e-6){return 1;}
    return 0;
}



void Sieving_sorting_3(void * a, size_t size, size_t elem_length, int (*cmp_3)(const void *, const void *)) // 3 реализация 
{
    char *ptr = a;
    void * begin = ptr;
    int k = size;
    for(int i=1; i<k; i++)
    {
        ptr+=(elem_length*i);
        for(size_t j=i; j>0 && cmp_3(ptr, (ptr-elem_length))==1; j--, ptr-=elem_length)
        {
            swap((ptr-elem_length), ptr, elem_length);
        }
        ptr = begin;
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
   
    if ((*ad - *bd)<-1e-12) {return 1;}   
    else if ((*ad - *bd)>1e-12) {return -1;}   
    else {return 0;}   
}



