#include"stdio.h"
#include"stdlib.h"
#include"time.h"

void countSort(int a[], int n, int place);
void radixSort(int a[], int n);
int getMax (int a[], int n);
// void print(int a[], int n);

// int main(void) {
//     int a[] = {121, 432, 564, 23, 1, 45, 788};
//     int n = sizeof(a) / sizeof(a[0]);

//     radixSort(a, n);
//     for(int i=0; i<n-1; i++){if(a[i]>a[i+1]){printf("ERROR!!!\n"); break;}}

//     print(a, n);
//     return 0;
// }
int main(void)
{
    int *a;
    int n=1e7;
    clock_t TimeStart, TimeStop;
    double cpu_time_used;
    int flag=0;

    a = (int*)malloc(n * sizeof(int));

    for(int i = 0; i<n; i++){a[i] = rand();} // заполнение массива

    TimeStart = clock()*1000/CLOCKS_PER_SEC;
    radixSort(a, n); 
    TimeStop = clock()*1000/CLOCKS_PER_SEC;

    cpu_time_used = ((double) (TimeStop - TimeStart))/1000;
    printf("time = %.3lf sec\n", cpu_time_used);

    for(int i = 0; i<n-1; i++) // проверка
    {
        if(a[i]>a[i+1]){flag =1;}
    }
    if(flag==1){printf("ERROR ");}

    free(a);
    return 0;
}

void radixSort(int a[], int n)
{
    int maxElement = getMax(a, n); // поиск наибольшего элемента

    for (int place = 1; (int)(maxElement / place) > 0; place *= 10) 
    {
        countSort(a, n, place);
    }
}

void countSort(int a[], int n, int place) 
{
    int *output;
    int count[10] = {0};
    output = (int*)malloc(n * sizeof(int));
    // print(a, n);
    printf("place = %d\n", place);
    for (int i = 0; i < n; i++) // записываем сколько раз повторяется цифра i в разряде place
    {
        count[(int)(a[i] / place) % 10]++;
    }
    for (int i = 1; i < 10; i++) // увеличиваем значение в count
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) // ставим элементы в соответствующие ячейки
    {
        output[count[(int)(a[i] / place) % 10] - 1] = a[i];
        count[(int)(a[i] / place) % 10]--;
    }
    for (int i = 0; i < n; i++) // перезаписываем массив
    {
        a[i] = output[i];
    }
    free(output);
}

int getMax (int a[], int n) // поиск наибольшего элемента
{
    int maxElement = a[0]; 
    for(int i=1; i<n; i++)
    {
        if(a[i]>maxElement){maxElement = a[i];}
    }
    return maxElement;
}

// void print(int a[], int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     printf("\n\n");
// }
