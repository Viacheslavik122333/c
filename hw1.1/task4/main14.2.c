#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Pow(int n, int p);

int main(void)
{
	int p;
    int n, res;
    printf("Ввести целое число: "); scanf("%d", &n);
    printf("Ввести целую степень: "); scanf("%d", &p);
    res = Pow(n, p);
    printf("Результат: %d \n", res);
    return 0;
}

int Pow(int n, int p)
{
	int res = 1, curr_pow = n;
	while (p){
		if(p & 1) {res *= curr_pow;}
        curr_pow *= curr_pow;
		p = p >> 1;
	}
	return res;
}