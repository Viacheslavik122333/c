#include"stdio.h"
#include"stdlib.h"
#include <math.h>

void fun(int M, int N, int L, int K, int *a);

int main(void)
{
    int M, N, L, K;
    FILE* f;
    FILE* fout;
    int *a;
    f = fopen("data.txt", "r");
    fout = fopen("res.txt", "w");
    if(!f || !fout){printf("1"); return -1;}
    fscanf(f, "%d %d %d %d", &M, &N, &L, &K);
    if(M==0 || N==0 || L==0 || K==0)
    {
        fclose(f);
        return -1;
    }
    a = (int*)malloc(L*K * sizeof(int));
    for (int i=0; i<L*K; i++)
    {
        if(!(fscanf(f, "%d", &a[i]))) 
        {
            printf("2"); 
            free(a);
            fprintf(fout,"ERROR\n");
            fclose(f); 
            fclose(fout); 
            return -1;
        }
    }
    fun(M, N, L, K, a);

    fprintf(fout, "%d %d %d %d\n", M, N, L, K);
    for (int i=0; i<L*K; i++)
    {
        if((i+1)%K==0){fprintf(fout, "\n");}
        fprintf(fout, "%d ", a[i]);
    }

    free(a);
    fprintf(fout,"ERROR\n");
    fclose(f); 
    fclose(fout); 
    return 0;
}

void fun(int M, int N, int L, int K, int *a)
{
#define A(i, j) a[(j) + (i)*K]

    int *columns = (int*)malloc(K * sizeof(int));
    int *lines = (int*)malloc(L * sizeof(int));
    int count1=0, count2=0;

    for(int i=0; i<L; i++)
    {
        for(int j=0; j<K; j++)
        {
            if(A(i,j)>=M && A(i,j)<=N)
            {
                lines[count1] = i;
                count1++;
                break;
            }
        }
    }
    for(int j=0; j<K; j++)
    {
        for(int i=0; i<L; i++)
        {
            if(A(i,j)>=M && A(i,j)<=N)
            {
                columns[count2] = j;
                count2++;
                break;
            }
        }
    }
    for(int j=0; j<count2; j++)
    {
        for(int i=0; i<count1; i++)
        {
            





        }
    }





    free(columns);
    free(lines);
    return;
#undef A
}


// 1 2 3 4
// 5 6 7 8
// 9 3 4 5
// 2 4 6 7

// 0 1 1 1 
// 0 0 0 0 
// 0 0 1 1 
// 0 0 1 1 