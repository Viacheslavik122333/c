#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int count_ones(int a);

int main(void)
{
    int M = 0, size=0, *a, bitM, bitM1;
    FILE* fin;
    FILE* fout;
    
    if(!(fin = fopen("input.txt", "r"))){
        return -1;
    }
    if(!(fout = fopen("output.txt", "w"))){
        fclose(fin);
        return -1;
    }

    if (fscanf(fin, "%d %d", &M, &size) != 1) {
        fclose(fin);
        fclose(fout);
        return -1;
    }

    if (M < 0 || M > 30) {
        fclose(fin);
        fclose(fout);
        return -1;
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

    for (int i = 0; i < size; i++) {
 
        bitM = (a[i] >> M) & 1;

        bitM1 = (a[i] >> (M + 1)) & 1;
        
        if (bitM == bitM1) {
            a[i] = count_ones(a[i]);
        }
    }

    return 0;
}

int count_ones(int a) {
    int count = 0;
    while (a) {
        count += (a & 1);
        a >>= 1;
    }
    return count;
}
