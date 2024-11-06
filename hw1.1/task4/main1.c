#include "stdio.h"
#include "stdlib.h"

int main (void)
{
    int x;
    // int count = 32;
    scanf("%d", &x);
    // printf("%b", -3);
    for (int i=32; i>=-1; i--)
    {
        x = x>>1;
        if(x == 0){printf("%d", i); return 0;}
    }
}
