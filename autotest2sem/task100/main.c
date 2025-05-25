#include "stdio.h"
#include "stdlib.h"

void fun(int M, int N, int L, int K, int *a);
int* memory(int n);

int main(void)
{
    int M, N, L, K;
    int *a;
    FILE* fin;
    FILE* fout;

    fin = fopen("data.txt", "r");
    if(!fin) {return -1;}

    fout = fopen("res.txt", "w");
    if(!fout) {fclose(fout); return -1;}

    if (fscanf(fin, "%d %d %d %d", &M, &N, &L, &K) != 4)
    {fprintf(fout, "ERROR\n"); fclose(fin); fclose(fout); return -1;}

    if (M < 0 || N < 0 || L < 0 || K < 0) 
    {
        fprintf(fout, "ERROR\n");
        fclose(fin);
        fclose(fout);
        return -1;
    }

    a = memory(L*K);
    if (a == NULL) 
    {
        printf("Ошибка создания массива a\n");
        fprintf(fout, "ERROR\n");
        fclose(fin);
        fclose(fout);
        return -1;
    }

    for(int i=0; i<L*K; i++)
    {
        fscanf(fin, "%d", &a[i]);
    }

    fun(M, N, L, K, a);

    fprintf(fout, "%d %d %d %d\n", M, N, L, K);
    for (int i=0; i<L*K; i++)
    {
        if((i)%K==0){fprintf(fout, "\n");}
        fprintf(fout, "%d ", a[i]);
    }
    free(a);
    fclose(fin);
    fclose(fout);
    return 0;
}

int *memory(int n)
{
    int *a;
    a = (int *)malloc(n * sizeof(int));
    return a;
}


void fun(int M, int N, int L, int K, int *a)
{
#define A(i,j)  a[(j) + (i)*K]
#define B(i,j)  copy[(j) + (i)*K]
    int *line = memory(L), *columns = memory(K), *X = memory(L*K), *copy = memory(L*K);
    int count1=0, count2=0, count3=0, tmp=0;

    // printf("%d\n", A(2,3)); 

    for(int i=0; i<L*K; i++)
    {
        copy[i]=a[i];
    }

    for(int i=0; i<L; i++)
    {
        for(int j=0; j<K; j++)
        {
            if(A(i,j)%M==N)
            {
                line[count1] = i;
                count1++;
                // printf("l: A(%d, %d) = %d, l[%d] = %d\n", i,j, A(i,j), count1, line[count1-1]);
                break;
            }
        }
    }

    for(int j=0; j<K; j++)
    {
        for(int i=0; i<L; i++)
        {
            if(A(i,j)%M==N)
            {
                columns[count2] = j;
                count2++;
                // printf("c: A(%d, %d) = %d, c[%d] = %d\n", i,j, A(i,j), count2, columns[count2-1]);
                break;
            }
        }
    }

    for(int j=0; j<count2; j++)
    {
        for(int i=0; i<count1; i++)
        {
            // printf("i = %d: %d\n", i, A(line[i], columns[j]));
            X[count3] = A(line[i], columns[j]);
            count3++;
        }
    }

    for(int j=0; j<count2; j++)
    {
        for(int i=0; i<count1; i++)
        {
            tmp=0;
            for(int k=0; k<count1; k++)
            {
                if(A(line[i], columns[j]) == B(line[k], columns[j]))
                {
                    tmp++;
                }
            }
            // printf("A = %d, tmp = %d \n", A(line[i], columns[j]), tmp);
            if (tmp >= 2) 
            {
                A(line[i],columns[j]) = 1;
            } 
            else 
            {
                A(line[i],columns[j]) = 0;
            }
            tmp=0;
        }
    }
    free(line);
    free(columns);
    free(X);
    free(copy);
#undef A
#undef B

}