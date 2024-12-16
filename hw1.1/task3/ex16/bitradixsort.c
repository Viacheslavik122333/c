#include "bitradixsort.h"

int main(void)
{
	long unsigned int N[5] = {1e5, 2e5, 4e5, 8e5, 1e6};
	clock_t t1, t2;
	double seconds;
	int j;
	size_t n, i;
	int k = 100; // число для заполнение массива (можно менять)
	unsigned int *a = (unsigned int *)malloc(N[4]*sizeof(int));
	unsigned int *b = (unsigned int *)malloc(N[4]*sizeof(int));
	bool flag;
	srand(k);
	printf("   Size   | Bitradixsort |  Qsort   |\n");
	for (j = 0; j < 5; ++j){
		n = N[j];
		printf("%8ld  |   ", n);

        for (i = 0; i < n; ++i) a[i] = (rand())/1000000; // заполнение массива числами
		t1 = clock();
		BitRadixSort(a, n, b); // битовая сортировка
		t2 = clock();
		seconds = (double)(t2-t1) / CLOCKS_PER_SEC;
		printf("%f   |", seconds);
		flag = (TestSort(n, a)); // проверка сортировка
		printf("%d\n", flag);
		// if (flag){printf("failure\n");}
		// printf("%s", (TestSort(n, a)) ? "" : "failure"); 

		for (i = 0; i < n; ++i) a[i] = (rand())/1000000; // заполнение массива числами
		t1 = clock();
		qsort(a, n, sizeof(unsigned int), CompareVoid); // быстрая сортировка для сравнения
		t2 = clock();
		seconds = (double)(t2-t1) / CLOCKS_PER_SEC;
		printf(" %f |\n", seconds);
		flag = (TestSort(n, a)); // проверка сортировка
		if (flag){printf("failure\n");}
		// printf("%s\n", (TestSort(n, a)) ? "" : "failure"); // проверка сортировка
	}
	free(a);
	free(b);
	return 0;
}
