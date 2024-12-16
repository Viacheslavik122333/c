#include"stdio.h"
#include"stdlib.h"
#include "math.h"
#include "time.h"

void mergesortVia(double a[], int left, int M);
void merge(double a[], int left, int mid, int N);
void buffer(double a[], int left, int mid, int N, int k);
void easysort(double a[],int left, int k, int K, int mid, int tmpK);
void mergetmp(double a[], int tmpK, int left, int mid, int N, int k, int K);
void sort1(double a[], int tmpK, int left, int mid, int N, int k);
void sort2(double a[], int left, int mid, int N, int k, int tmpK2);
void sdvig(double a[], int i, int c);
void sdvig2(double a[], int left, int count);
void swap(double a[], int k, int l, int r);


int main(void)
{
    double *array;
    double G=1e6;
    int M=1e6;
    clock_t TimeStart, TimeStop;
    double cpu_time_used;
    int flag=0;

    array = (double*)malloc(M * sizeof(double));

    for(int i = 0; i<M; i++){array[i] = ((rand())/((double)(RAND_MAX))) * 2*G - G;} // заполнение массива

    TimeStart = clock()*1000/CLOCKS_PER_SEC;
    mergesortVia(array, 0, M); 
    TimeStop = clock()*1000/CLOCKS_PER_SEC;

    cpu_time_used = ((double) (TimeStop - TimeStart))/1000;
    printf("time = %lf\n", cpu_time_used);

    for(int i = 0; i<M-1; i++) // проверка
    {
        if((array[i]-array[i+1])>-1e-12)
        {
            flag =1;
        }
    }
    if(flag==1){printf("ERROR ");}

    free(array);
    return 0;
}

void mergesortVia(double a[], int left, int N) // сама сортировка
{
    if(left+1<left+N)
    {
        int mid = (int)(N/2)+left;
        mergesortVia(a, left, mid-left);
        mergesortVia(a, mid, N-(mid-left));
        merge(a, left, mid, N);
    }
    return;
}

void merge(double a[], int left, int mid, int N) // функция слияния
{
    double d = sqrt(N);
    int k = (int)d; // длина подотрезка
    int K=0; // колличесво подотрезков
    int tmp = mid; 
    int tmpK=0; // количесто элементов до начала участнов деления
    int tmpK2=0; // количесто элементов после участнов деления
    for(int i=0; tmp>=left+k; i++, K++){tmp-=k;tmpK++;}
    tmp = mid;
    for(int i=0; tmp<=left+N-(2*k); i++, K++){tmp+=k;tmpK2++;}

    buffer(a, left, mid, N, k); // создание буфера

    easysort(a, left, k, K, mid, tmpK); // меняем отрезки по возрастанию первого элемента
    
    mergetmp(a, tmpK, left, mid, N, k, K); // сливаем отрезки
    
    sort1(a, tmpK, left, mid, N, k); // сортируем первые элементы

    sort2(a, left, mid, N, k, tmpK2); // сортируем оставшиеся элементы
}

void buffer(double a[], int left, int mid, int N, int k) // создание буфера (последние k элементов)
{
    double tmp;
    int count=0;
    for(int i=0; i<k; i++)
    { 
        if((a[mid-1]-a[N+left-1-i])>1e-6)
        {
            tmp = a[N+left-1-i]; 
            for(int j=mid-1; j>=left; j--)
            {
                if((tmp - a[j])>1e-6)
                {
                    a[N+left-1-i] = a[mid-1];
                    sdvig(a, mid-1, count);
                    a[j+1] = tmp;
                    break;
                }
                if(j==left)
                {
                    a[N+left-1-i] = a[mid-1];
                    sdvig(a, mid-1, count);
                    a[j] = tmp;
                    break;
                }
                count++;
            }
            count=0;
        }
    }
}

void easysort(double a[],int left, int k, int K, int mid, int tmpK) // простая сортировка
{
    int quantity = mid - left - k*tmpK;

    for(int i=left+quantity+k; i<left+quantity+k*K; i+=k)
    {
        for(int j=i; j>left+quantity && (a[j-k]-a[j])>1e-6; j-=k)
        {
            swap(a, k, j-k, j);
        }
    }
}

void mergetmp(double a[], int tmpK, int left,  int mid, int N, int k, int K) // слияние подотрезков
{
    int tmp1=0; // идекс начала первого отвезка
    double tmp;
    int r;
    int x = mid - k*tmpK;
    for(int i=0; i<K-1; i++) 
    {
        tmp1=i*k+x; 
        for(int j=0; j<k; j++) // меняем буфер и второй отрезок
        {
            tmp = a[tmp1+k+j]; //=7
            a[tmp1+k+j] = a[N+left-k+j];
            a[N+left-k+j] = tmp;
        }

        r = tmp1-1;

        for(int j=0; j<k; j++) //сливаем 2 отрезка
        {
            tmp = a[tmp1+k+j];
            while(r<=tmp1+k+j)
            {
                r++;
                if((a[r] - a[N+left-k+j])>1e-6 || r == tmp1+k+j)
                {
                    sdvig(a, tmp1+k+j, tmp1+k+j-r);
                    a[r] = a[N+left-k+j];
                    a[N+left-k+j] = tmp;
                    break;
                }   
            }
        }
    }
}

void sort1(double a[], int tmpK, int left, int mid, int N, int k) // сортировка первых элементов
{
    double tmp;
    int quantity = mid - left - k*tmpK;
    int j=left+quantity-1;
    int count=quantity-1;
    for(int i=0; i<quantity; i++)
    {
        tmp = a[left];
        while(j<left+N)
        {
            count++;
            j++;
            if((a[j]-tmp)>1e-6)
            {
                sdvig2(a, left, count);
                a[j-1]=tmp;
                j--;
                count--;
                break;
            }
        }
    }
}

void sort2(double a[], int left, int mid, int N, int k, int tmpK2) // сортировка элементов до буфера
{
    int quantity = left + N - mid - k*tmpK2-k;
    int index = mid+k*tmpK2 + quantity-1;
    double tmp;
    int j=index-quantity;
    int count=quantity;
    for(int i=0; i<quantity; i++)
    {
        tmp = a[index];
        while(j>=left)
        {
            if((tmp - a[j])>1e-6 || j==left)
            {
                sdvig(a, index, count);
                if(j==left && (a[j]-tmp)>1e-6){a[j]=tmp;}
                else{a[j+1]=tmp;}
                break;
            }
            count++;
            j--;
        }
    }
}


void sdvig2(double a[], int left, int count) // вспомогательные функции сдвигов
{
    for(int i=left; i<count+left; i++)
    {
        a[i]=a[i+1];
    }
}
void sdvig(double a[], int i, int count)
{
    while(count>0)
    {
        a[i]=a[i-1];
        i--;
        count--;
    }
}

void swap(double a[], int k, int l, int r)
{
    double tmp;
    for (int j=0; j<k; j++)
    {
        tmp = a[l+j];
        a[l+j] = a[r+j];
        a[r+j] = tmp;
    }
}