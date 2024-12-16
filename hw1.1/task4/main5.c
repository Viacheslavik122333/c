#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int swap(int a); // меняет число (по битово на зеркальное)
void Translation1(int a, int *b); //переводит число из 10-ой в 2-ую систему счисления, но не меняю порядок(т.е. сразу в зеркальную)
int Translation2(int * b); //переводит число из 2-ой в 10-ую систему счисления
void fun(int i, int *a); // фунция

int main(void)
{
    int N, i=0, j=0;
    int arr[2];
    printf("Введите число N: ");
    scanf("%d", &N);
    while(j<N)
    {
        fun(i, arr);
        if(arr[0] == swap(arr[1])){ printf("%d ", i); j++;}
        i++;
    }
    return 0;
}
void fun(int i, int *a)
{
    a[0] = i%256;
    i = (int)(i/256);
    a[1] = i%256;
    return;
}

int swap (int a)
{
    int b[8];
    Translation1(a, b);
    return Translation2(b);
}
void Translation1(int a, int *b)
{
    for(int i=0; i<8; i++)
    {
        b[i]=a%2;
        a = (int)(a/2);
    }
}
int Translation2(int * b)
{
    int res=0;
    int j=7;
    for(int i=0; i<8; i++)
    {
        res += b[i] * pow(2, j);
        j--;
    }
    return res;
}