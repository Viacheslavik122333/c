#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

int main(void) 
{
    int numPoints;        // Количество точек
    double a = 50.0;           // Полуось по X
    double b = 30.0;           // Полуось по Y
    double centerX = 0.0;      // Центр X
    double centerY = 0.0;      // Центр Y
    
    FILE* file = fopen("points.txt", "w");
    if (file == NULL) {
        printf("Ошибка создания файла\n");
        return 1;
    }

    printf("Кол-во вершин:\n");
    scanf("%d", &numPoints);
    
    fprintf(file, "%d\n", numPoints);

    double angleStep = 2 * M_PI / numPoints;

    for (int i = 0; i < numPoints; i++) 
    {
        double angle = i * angleStep;
        double x = centerX + a * cos(angle);
        double y = centerY + b * sin(angle);
        
        fprintf(file, "%.3f %.3f\n", x, y);
        // printf("Точка %d: (%.3f, %.3f)\n", i + 1, x, y);
    }
    
    fclose(file);
    // printf("\nКоординаты сохранены в файл points.txt\n");
    
    return 0;
}