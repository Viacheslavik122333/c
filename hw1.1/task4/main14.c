#include "stdio.h"
#include "stdlib.h"
#include "math.h"

double fun (double m, int N);

int k = 1; // количесво итераций 

int main(void)
{
    int N;
    double m, res;
    printf("Ввести вещественное число: "); scanf("%lf", &m);
    printf("Ввести целую степень: "); scanf("%d", &N);
    res = fun(m, N);
    printf("Результат: %.3lf \nКоличесво итераций: %d\n", res, k);
    return 0;
}

double fun (double m, int N)
{
    double tmp = m;
    int i=1;
    while(i*2<N)
    {
        tmp*=tmp;
        i*=2;
        k++;
    }
    if(N-i == 0){return m;}
    return tmp * fun(m,N-i);
}

