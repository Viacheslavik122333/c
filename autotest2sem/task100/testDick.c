#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int M, N, L, K;
    int **matrix;
    int *valid_rows;
    int *valid_cols;
    int count;
    FILE *input_file = fopen("data.txt", "r");
    FILE *output_file = fopen("res.txt", "w");
    
    if (input_file == NULL || output_file == NULL) {
        fprintf(output_file, "ERROR");
        fclose(input_file);
        fclose(output_file);
        return -1;
    }
    
    if (fscanf(input_file, "%d %d %d %d", &M, &N, &L, &K) != 4) {
        fprintf(output_file, "ERROR");
        fclose(input_file);
        fclose(output_file);
        return -1;
    }
    
    matrix = (int **)malloc(L * sizeof(int *));
    if (matrix == NULL) {
        fprintf(output_file, "ERROR");
        fclose(input_file);
        fclose(output_file);
        return -1;
    }
    
    for (int i = 0; i < L; i++) {
        matrix[i] = (int *)malloc(K * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            fprintf(output_file, "ERROR");
            fclose(input_file);
            fclose(output_file);
            return -1;
        }
        for (int j = 0; j < K; j++) {
            if (fscanf(input_file, "%d", &matrix[i][j]) != 1) {
                for (int k = 0; k <= i; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                fprintf(output_file, "ERROR");
                fclose(input_file);
                fclose(output_file);
                return -1;
            }
        }
    }
    
    // Находим строки, содержащие хотя бы один элемент с matrix[i][j] % M == N
    valid_rows = (int *)calloc(L, sizeof(int));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            if (matrix[i][j] % M == N) {
                valid_rows[i] = 1;
                break;
            }
        }
    }
    
    // Находим столбцы, содержащие хотя бы один элемент с matrix[i][j] % M == N
    valid_cols = (int *)calloc(K, sizeof(int));
    for (int j = 0; j < K; j++) {
        for (int i = 0; i < L; i++) {
            if (matrix[i][j] % M == N) {
                valid_cols[j] = 1;
                break;
            }
        }
    }
    
    // Обрабатываем элементы, принадлежащие пересечению valid_rows и valid_cols
    for (int i = 0; i < L; i++) {
        if (!valid_rows[i]) continue;
        for (int j = 0; j < K; j++) {
            if (!valid_cols[j]) continue;
            
            count = 0;
            for (int k = 0; k < L; k++) {
                if (valid_rows[k] && matrix[k][j] == matrix[i][j]) {
                    count++;
                }
            }
            
            if (count >= 2) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Записываем результат в файл
    fprintf(output_file, "%d %d %d %d\n\n", M, N, L, K);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            fprintf(output_file, "%d", matrix[i][j]);
            if (j < K - 1) {
                fprintf(output_file, " ");
            }
        }
        if (i < L - 1) {
            fprintf(output_file, "\n");
        }
    }
    
    // Освобождаем память
    for (int i = 0; i < L; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(valid_rows);
    free(valid_cols);
    
    fclose(input_file);
    fclose(output_file);
    return 0;
}