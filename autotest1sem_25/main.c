#include <stdio.h>
#include <stdlib.h>

void WriteData(FILE* fout, int* data, int size);

void WriteData(FILE* fout, int* data, int size) {
    for (int k = 0; k < size; k++) {
        fprintf(fout, "%d ", data[k]);
    }
}


int main(void)
{
    int size=0, N, M, count=0, tmp=0, prev;
    int *arr, *ind, *arr2;
    FILE* fin;
    FILE* fout;

    if ( !(fin = fopen("input.txt", "rt")) ) {
        return -1;
    }
    
    if ( !(fout = fopen("output.txt", "wt"))) {
        fclose(fin);
        return -1;
    }
    
    if ( fscanf(fin, "%d%d%d", &M, &N, &size) != 3) { 
        fclose(fin);
        fclose(fout);
        return -1;
    }
    
    if (M == 0) {
        fclose(fin);
        fclose(fout);
        return -1;
    }

    if (size < 0) {
        fclose(fin);
        fclose(fout);
        return -1;
    }

    if (size == 0) {
        fclose(fin);
        fclose(fout);
        return 0;
    }

    
    if ( !(arr = (int*) malloc(sizeof(int) * size))) {
        fclose(fin);
        fclose(fout);
        return -1;
    }

    for (int i = 0; i < size; ++i) {
        if (fscanf(fin, "%d", &arr[i]) != 1) {
            free(arr);
            fclose(fin);
            fclose(fout);
            return -1;
        }
        if(arr[i] < 0){
            free(arr);
            fclose(fin);
            fclose(fout);
            return -1;
        }
    }

    if ( !(ind = (int*) malloc(sizeof(int) * size))) {
        fclose(fin);
        fclose(fout);
        free(arr);
        return -1;
    }

    for(int i=0; i<size; ++i)
    {
        if(arr[i] % M == N)
        {
            ind[i] = 1;
            ++count;
        }
        else
        {
            ind[i]=0;
        }
    }

    if ( !(arr2 = (int*) malloc(sizeof(int) * count))) {
        fclose(fin);
        fclose(fout);
        free(arr);
        free(ind);
        return -1;
    }

    tmp=0;
    for(int i=0; i<size; ++i)
    {
        if(ind[i] == 1)
        {
            arr2[tmp] = arr[i];
            tmp++;
        }
    }

    prev = arr2[0];

    for(int i=1; i<count-1; ++i)
    {
        tmp = arr2[i];
        arr2[i] = (prev + arr2[i+1])/2;
        prev = tmp;
    }

    tmp=0;

    for(int i=0; i<size; ++i)
    {
        if(ind[i] == 1)
        {
            arr[i] = arr2[tmp];
            tmp++;
        }
    }

    WriteData(fout, arr, size);

    free(arr);
    fclose(fin);
    fclose(fout);   
    return 0;
}
