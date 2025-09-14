#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef struct
{
    int x;
    int y;
    double meaning;
    int count;
}Point;

typedef struct // с вещественными координатами (для поиска точки)
{
    double x;
    double y;
    double meaning;
    int count;
}Point2;

typedef struct 
{
    double k;
    double b;
} Line;

Point2 centrpoint (Point2 a, Point2 b);
double calculate_polygon_area(Point points[], int numVertices);
double calculate_polygon_area2(Point2 points[], int numVertices);
void fun(Point* points, double area, int numVertices);
Line division(Point2 a, Point2 b, Point2 p);
Point * array(FILE*fin, int numVertices);
// void Print(Point*a, int b);
// void Print2(Point2*a, int b);

//создание массива
Point * array(FILE*fin, int numVertices)
{
    Point* vertices = (Point*)malloc(numVertices * sizeof(Point));

    if (vertices == NULL) 
    {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    for (int i=0; i<numVertices; i++)
    {
        fscanf(fin, "%d %d", &vertices[i].x, &vertices[i].y);
    }

    return vertices;
}

// функции для вычисления площади многоугольника
double calculate_polygon_area(Point points[], int numVertices)
{

    double area = 0.0;
    int j;

    if (numVertices < 3) 
    {
        printf("Ошибка: Для многоугольника нужно минимум 3 точки\n");
        return 0.0;
    }
    
    // Применяем формулу шнуровки
    for (int i = 0; i < numVertices; i++) 
    {
        j = (i + 1) % numVertices;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }
    
    area = fabs(area) / 2.0;
    
    return area;
}

double calculate_polygon_area2(Point2 points[], int numVertices)
{
    double area = 0.0;
    int j;

    if (numVertices < 3) 
    {
        printf("Ошибка: Для многоугольника нужно минимум 3 точки\n");
        return 0.0;
    }
    
    // Применяем формулу шнуровки
    for (int i = 0; i < numVertices; i++) 
    {
        j = (i + 1) % numVertices;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }

    area = fabs(area) / 2.0;
    
    return area;
}

// Главная вычислительная функция 
void fun(Point* points, double area, int numVertices)
{
    double res=0, tmp=0, res1, res2;
    Point p1 = points[1], p2 = points[2];
    Point2 a, b, p;
    Line line;

    p1.meaning = 100000; p2.meaning = 10000;

    for(int i = 2; i < numVertices; i++)
    {
        res1 = calculate_polygon_area(points, i+1);
        // printf("res1 = %lf, %d\n", res1, i+1);
        res2 = area - res1; 
        res  = (res1 < res2) ? res1 : res2;
        tmp = area/2 - res;

        // printf("tmp = %lf\n", tmp);

        if(tmp <= p1.meaning)
        {
            p2 = p1;
            p1 = points[i];
            p1.meaning = tmp;
            p1.count = i+1;
        }
        else if(tmp <= p2.meaning)
        {
            p2 = points[i];
            p2.meaning = tmp;
            p2.count = i+1;
        }

        // printf("%d == %d %d --- %lf, %d %d --- %lf\n", i, p1.x, p1.y, p1.meaning, p2.x, p2.y, p2.meaning);
    }

    // printf("itog == %d %d -- %d, %lf, %d %d -- %d\n", p1.x, p1.y, p1.count, p1.meaning, p2.x, p2.y, p2.count);

    a.x = p1.x; a.y = p1.y, a.meaning = p1.meaning; a.count = p1.count;
    b.x = p2.x; b.y = p2.y, b.meaning = p2.meaning; b.count = p2.count;
    p.x = points[0].x; p.y=points[0].y;

    line = division(a, b, p);

    printf("Прямая: y = (%lf)x + (%lf);\n", line.k, line.b);

}

// бинарный поиск для отвезка 
Line division(Point2 a, Point2 b, Point2 p)
{
    Line res;
    double eps = 1e-6, tmp=0;
    Point2 array[3] = {p,a,b};
    Point2 center = centrpoint(a, b);
    double value = a.meaning;
    int count=0;

    tmp = calculate_polygon_area2(array, 3);

    while (fabs(tmp-value)>eps)
    {
        count++;
        array[2] = center;
        tmp = calculate_polygon_area2(array, 3);

        if(fabs(tmp-value)<eps)
        {
            // printf("da!\n");
            break;
        }

        if(tmp > value)
        {
            b = center;
            center = centrpoint(a, b);
            
        }
        else 
        {
            a = center;
            center = centrpoint(a, b);
        }
    }
    // printf("ura   ==    %lf %lf, %d\n", center.x, center.y, count);
    // printf("%lf, %lf\n", p.x, p.y);

    res.k = (double)(center.y - p.y) / (double)(center.x - p.x);
    res.b = p.y - res.k * p.x;

    return res;
}

//ищет точку между двумя другими
Point2 centrpoint (Point2 a, Point2 b)
{
    Point2 c;
    c.x = (double)(a.x + b.x)/2;
    c.y = (double)(a.y + b.y)/2;
    return c;
}

int main(void)
{
    int numVertices;
    double area = 0;
    Point* points; 
    clock_t t1, t2;

    FILE* fin = fopen("points.txt", "r");   //файл с координатами точек

    if (fin == NULL) 
    {
        return -1;
    }
    fscanf(fin, "%d", &numVertices); // кол-во точек в многоугольнике (первое число в файле)
    
    points = array(fin, numVertices);

    // Print(points, numVertices);

    area = calculate_polygon_area(points, numVertices);

    printf("S = %lf\n", area);

    t1 = clock();
    fun(points, area, numVertices);
    t2 = clock();

    printf("Время выполнения: %.6f секунд\n", ((double)(t2 - t1)) / CLOCKS_PER_SEC);

    free(points);
    fclose(fin);
    return 0;
}


// для проверок
// void Print(Point*a, int b)
// {
//     printf("num = %d\n", b);
//     for(int i=0; i<b; i++)
//     {
//         printf("%d %d\n", a[i].x, a[i].y);
//     }
// }

// void Print2(Point2*a, int b)
// {
//     printf("NUM = %d\n", b);
//     for(int i=0; i<b; i++)
//     {
//         printf("%d = %lf %lf\n", i, a[i].x, a[i].y);
//     }
// }



