#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int cmp(const void* a, const void* b);

int main(void)
{
    int M = 0, N = 0, size = 0, sum = 0, *A, *k, *b, count=0;
    double sr_arifm, delta;
    FILE* fin;
    FILE* fout;
    
    if(!(fin = fopen("input.txt", "r"))){
        return -1;
    }
    if(!(fout = fopen("output.txt", "w"))){
        fclose(fin);
        return -1;
    }

    if (fscanf(fin, "%d %d %d", &M, &N, &size) != 3) {
        fclose(fin);
        fclose(fout);
        return -1;
    }

    if (N == 0) {
        fclose(fin);
        fclose(fout);
        return -1;
    }

    if (size <= 0) {
        fclose(fin);
        fclose(fout);
        return 0;
    }


    A = (int*)malloc(size * sizeof(int));
    k = (int*)malloc(size * sizeof(int));
    b = (int*)malloc(size * sizeof(int));

    if (!A || !k || !b) {
        free(A);
        free(k);
        free(b);
        fclose(fin);
        fclose(fout);
        return -1;
    }

    for (int i = 0; i < size; ++i) {
        if (fscanf(fin, "%d", &A[i]) != 1) {
            free(A);
            free(k);
            free(b);
            fclose(fin);
            fclose(fout);
            return -1;
        }
        sum += A[i];
    }
    fclose(fin);

    sr_arifm = (double)sum / (double)size;
    delta = (double)M / N;

    count = 0;
    for (int i = 0; i < size; ++i) {
        if (fabs(A[i] - sr_arifm) <= delta) {
            k[count] = i;     
            b[count] = A[i];
            count++;
        }
    }
    qsort(b, count, sizeof(int), cmp);

    for (int i = 0; i < count; ++i) A[k[i]] = b[i];


    for (int i = 0; i < size; ++i) {
        fprintf(fout, "%d", A[i]);
        if (i < size - 1) fprintf(fout, " ");
    }

    free(A);
    free(k);
    free(b);
    fclose(fout);   
    return 0;
}

int cmp(const void* a, const void* b)
{
    const int A = *(const int*)a;
    const int B = *(const int*)b;
    if (A > B) return 1;
    if (A < B) return -1;
    return 0;
}
