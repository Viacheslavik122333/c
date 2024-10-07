#include"task12.h"

void task12(int a[], int size, int k)
{
    int i, j;
    int tmp, pred, q;
    if(k>size)
    {
        k=k%size;
    }
    if(k < 0)
	{
        k = size + k;
    }
    q = nod(size, k);
    for(i = q - 1; i >= 0; i--){
		pred = a[i];
		for(j = (i + k) % size; j != i; j = (j + k) % size){
			tmp = a[j];
			a[j] = pred;
			pred = tmp;
		}
		a[i] = pred;
	}
}

int nod(int a, int b)
{
    if(a==b) return a;
    if(a>b)
    {
        a=a-b;
    }
    else
    {
        b=b-a;
    }
    return nod(a,b);
}

// void task11(int *arr, int size, int k)
// {
//     if(k>size)
//     {
//         k=k%size;
//     }
//     for (int i=0; i<k; i++)
//     {
//         sdvig(arr, size);
//     }
// }

// void sdvig(int *arr, int size)
// {
//     int tmp;
//     arr=arr+(size-1);
//     tmp=*arr;
//     size--;
//     while(size>0)
//     {
//         *arr=*(arr-1);
//         arr--;
//         size--;
//     }
//     *arr=tmp;
// }
