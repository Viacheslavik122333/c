#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void print (int a[32][32]);

int main(void)
{
    int k, flag1=0, flag2=0;
    int a[32][32];
    printf("Введите длину одной ячейки: ");
    scanf("%d", &k);

    for(int i=0; i<32; i++)
    {
        flag1 = (i/k)%2;
        for(int j=0; j<32; j++)
        {
            flag2 = ((j/k)%2 + flag1)%2;
            a[i][j] = flag2;
        }
    }
    print(a);
    return 0;
}

void print (int a[32][32])
{
    for(int i=0; i<32; i++)
    {
        for(int j=0; j<32; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}