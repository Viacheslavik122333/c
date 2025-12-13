#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int M = 0, N = 0, size = 0, *a, count=0;
    double q, tmp;
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
    }
    fclose(fin);

    q = ((double)M) / ((double)N);

    if(M<1) M=1;
    if(N>size) N = size; // хз надо ли это

    for(int i=M-1; i<N; ++i)
    {
        tmp = a[i] * q;
        for(int j=i; j<N; ++j)
        {
            if((tmp - a[j])>1e-9) ++count;
        }
        a[i]=count;
        count=0;
    }

    for (int i = 0; i < size; ++i) {
        fprintf(fout, "%d", a[i]);
        if (i < size - 1) fprintf(fout, " ");
    }

    free(a);
    fclose(fout);
    return 0;
}
