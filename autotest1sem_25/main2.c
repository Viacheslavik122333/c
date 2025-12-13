#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int M = 0, N = 0, size = 0, sum = 0, *a;
    double sr_arifm, q;
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

    if (N == 0 || size < 0) {
        fclose(fin);
        fclose(fout);
        return -1;
    }

    if (size == 0) {
        fclose(fin);
        fclose(fout);
        return 0;
    }

    if (!(a = (int *)malloc(size * sizeof(int)))) {
        fclose(fin);
        fclose(fout);
        return -1;
    }
    for (int i = 0; i < size; ++i) {
        if (fscanf(fin, "%d", &a[i]) != 1) {
            free(a);
            fclose(fin);
            fclose(fout);
            return -1;
        }
        sum += a[i];
    }
    fclose(fin);

    q = ((double)M) / ((double)N);
    sr_arifm = ((double)sum) / ((double)size);

    for(int i=1; i<size-1; ++i)
    {
        if(fabs(a[i] - (sr_arifm * q)) < 1e-9)
        {
            a[i] = (a[i-1] + a[i+1])/2;
        }
    }

    for (int i = 0; i < size; ++i) {
        fprintf(fout, "%d", a[i]);
        if (i < size - 1) fprintf(fout, " ");
    }
    free(a);
    fclose(fout);
    return 0;
}
