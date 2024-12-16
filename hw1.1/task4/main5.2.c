#include <stdio.h>
#include <stdlib.h>

void fun(int n);
 
int main(void)
{
    int N;
    printf("Введите число N: ");
    scanf("%d", &N);
    fun(N);
    return 0;
}
 
void fun(int N)
{
    unsigned long a;
    int k, l, tmp = 0;
    
    for (unsigned long j = 0; tmp < N; j++) 
    {
        for (int i = 0; i < 256 && tmp < N; i++) 
        {
            a = (i << 8) + (j << 16);
            
            for (k = 7, l = 0; l < 8; k--, l++) 
            {
                if ((i >> k) & 1) 
                {
                    a += (1 << l);
                }
            }

            printf("%ld ", a);
            tmp++;
        }
        printf("\n Номер j: %ld\n", j);
    }
}

