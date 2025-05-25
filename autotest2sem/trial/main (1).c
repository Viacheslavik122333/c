#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double **FreeMatrix (double **a, int rows);
double **CreateMatrix (int rows, int cols);
void PrintMatrix(double **a, int rows, int cols, FILE *out);


void PrintMatrix (double **a, int rows, int cols, FILE *out) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(out, "%lg ", a[i][j]);
        }
        fprintf(out, "\n");
    }
}


double **FreeMatrix (double **a, int rows) {
    int i;
    if (a == NULL) return NULL;
    for (i = 0; i < rows; i++) {
        if (a[i] != NULL) free (a[i]);
    }
    free(a);
    return 0;
}


double **CreateMatrix (int rows, int cols) {
    int i, j;
    double **a;
    a = (double **)malloc(rows * sizeof(double *));
    if (a == NULL) return NULL;
    for (i = 0; i < rows; i++) {
        a[i] = (double *)malloc(cols * sizeof(double));
        if (a[i] == NULL) {
            FreeMatrix(a, i);
            return NULL;
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            a[i][j] = 0;
        }
    }
    return a;
}


int main(void) {
    // L = rows, K = cols
    int M, N, L, K;
    int i, j, k, l;
    double **a, **c;
    FILE *in, *out;
    int *cls, *rws;
    int check = 0;
    //int newrw = 0, newcl = 0;
    double EPS = 1e-15;

    in = fopen("data.txt", "r");
    if(!in) {
        perror("Ошибка открытия входного файла");
        return -1;
    }

    out = fopen("res.txt", "w");
    if(!out) {
        perror("Ошибка открытия выходного файла");
        fclose(out);
        return -1;
    }

    if (fscanf(in, "%d", &M) != 1) {
        fclose(in);
        fclose(out);
        printf("Не прочитано M\n");
        fprintf(out, "ERROR\n");
        return -1;
    }
    
    if (fscanf(in, "%d", &N) != 1) {
        fclose(in);
        fclose(out);
        printf("Не прочитано N\n");
        fprintf(out, "ERROR\n");
        return -1;
    }
    
    if (fscanf(in, "%d", &L) != 1) {
        fclose(in);
        fclose(out);
        printf("Не прочитано L\n");
        fprintf(out, "ERROR\n");
        return -1;
    }

    if (fscanf(in, "%d", &K) != 1) {
        fclose(in);
        fclose(out);
        printf("Не прочитано K\n");
        fprintf(out, "ERROR\n");
        return -1;
    }

    if (L < 0 || K < 0) {
        fclose(in);
        fclose(out);
        printf("Отрицательные значения количества строк или столбцов\n");
        fprintf(out, "ERROR\n");
        return -1;
    }
    
    rws = (int *)malloc(L * sizeof(int));
    if (rws == NULL) {
        fclose(in);
        fclose(out);
        printf("Ошибка создания массива rws\n");
        fprintf(out, "ERROR\n");
        return -1;
    }
    
    cls = (int *)malloc(K * sizeof(int));
    if (cls == NULL) {
        fclose(in);
        fclose(out);
        free(rws);
        printf("Ошибка создания массива cls\n");
        fprintf(out, "ERROR\n");
        return -1;
    }

    a = CreateMatrix(L, K);
    if (a == NULL) {
        fclose(in);
        fclose(out);
        free(rws);
        free(cls);
        printf("Ошибка при создании матрицы A\n");
        fprintf(out, "ERROR\n");
        return -1;
    }

    c = CreateMatrix(L, K);
    if (c == NULL) {
        fclose(in);
        fclose(out);
        free(rws);
        free(cls);
        FreeMatrix(a, L);
        printf("Ошибка при создании матрицы C\n");
        fprintf(out, "ERROR\n");
        return -1;
    }

    for (i = 0; i < L; i++) {
        for (j = 0; j < K; j++) {
            if (fscanf(in, "%lf", &a[i][j]) != 1) {
                FreeMatrix(a, L);
                fclose(in);
                fclose(out);
                free(rws);
                free(cls);
                printf("Ошибка чтения значения элемента матрицы\n");
                fprintf(out, "ERROR\n");
                return -1;
            }
            c[i][j] = a[i][j];
        }
    }
    fclose(in);
    
    
    for (i = 0; i < L; i++) {
        rws[i] = 0;
        for (j = 0; j < K; j++) {
            if ((a[i][j] >= M) && (a[i][j] <= N)) {
                rws[i] = 1;
                break;
            }
        }
        //newrw++;
    }
    
    for (j = 0; j < K; j++) {
        cls[j] = 0;
        for (i = 0; i < L; i++) {
            if ((a[i][j] >= M) && (a[i][j] <= N)) {
                cls[j] = 1;
                break;
            }
        }
        //newcl++;
    }
    
    for (i = 0; i < L; i++) {
        if (rws[i] == 0) continue;
        for (j = 0; j < K; j++) {
            check = 0;
            if (cls[j] == 0) continue;
            for (k = 0; k < L; k++) {
                //if (rws[k] == 0) continue;
                for (l = 0; l < j; l++) {
                    if (cls[l] == 0) continue;
                    if (fabs(a[i][j] - c[k][l]) < EPS) {
                        a[i][j] = 1;
                        check = 1;
                        break;
                    }
                }
                if (check == 1) break;
            }
            if (check == 0) a[i][j] = 0;
        }
    }
    
    fprintf(out, "%d %d %d %d\n", M, N, L, K);
    PrintMatrix(a, L, K, out);

    fclose(out);
    FreeMatrix(a, L);
    FreeMatrix(c, L);
    free(cls);
    free(rws);
    return 0;
} 
