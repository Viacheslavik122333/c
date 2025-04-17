#include "header.h"

int SortMatrix(int **arr, int m, int n, int M, int N)
{
    int quantity1=0, quantity2=0, tmp=0, number=-1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<m; j++)
        {
            if(arr[j][i]%M == 0)
            {
                tmp=1;
            }
            if(arr[j][i]%N == 0)
            {
                quantity2++;
            }
        }
        if(tmp == 0){quantity2=0;}
        else
        {
            if(number!=-1)
            {
                if(quantity1>= quantity2)
                {
                    DeleteMatrix(arr, i, m, n);
                }
                else
                {
                    DeleteMatrix(arr, number, m, n);
                }
                quantity1 = quantity2 = tmp = 0;
                i--;
                n--;
                number=-1;
            }
            else
            {
                number = i;
                quantity1 = quantity2;
                quantity2 = tmp = 0;
            }

        }
    }
    return n;
}

void DeleteMatrix(int **arr, int k, int m, int n)
{
    if(k==n-1){return;}
    for(int j = k; j<n-1; j++)
    {
        for(int i=0; i<m; i++)
        {
            arr[i][j] = arr[i][j+1];
        }

    }
}

int** mallocMatrix(int m, int n) 
{
    int num = -1;
    int **arr = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < n; i++) 
    {
        arr[i] = (int*)malloc(n * sizeof(int)); 
    }
    for(int j = 0; j < m; j++) 
    {
        if(!arr[j])
        {
            num = j;
            break;
        }
    }
    if(!arr) 
    {
        printf("Error! Cannot allocate memory\n");
        free(arr);
        exit(-1);
    }
    if(num >= 0) 
    {
        printf("Error! Cannot allocate memory\n");
        for(int k = 0; k < num; k++) 
        {
            free(arr[k]);
        }
        exit(-1);
    }
    return arr;
}

void fillMatrix(int **arr, int m, int n, FILE *f) 
{
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            fscanf(f, "%d", &arr[i][j]);
        }
    }
}

void PrintMatrix(int **arr, int m, int n)
{
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **arr, int m) 
{
    for(int i = 0; i < m; i++) 
    {   
        free(arr[i]); 
    }
    free(arr);
}

