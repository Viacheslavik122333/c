#include"task1.h"

int main(void)
{
    double G=1e6;
    double *array;
    double *tmparray;
    int tmpcount=0;

    clock_t TimeStart, TimeStop;
    double cpu_time_used;

    int quantity[5] = {1e4, 2*1e4, 4*1e4, 8*1e4, 1e5}; // длины массива

    double res[20];
    int count=0;
    int examination=0;

    srand(time(NULL));

    for (int r=0; r<5; r++)
    {
        array = (double*)malloc(quantity[r] * sizeof(double));

        for(int i = 0; i<quantity[r]; i++){array[i] = ((rand())/((double)(RAND_MAX))) * 2*G - G;}

        TimeStart = clock()*1000/CLOCKS_PER_SEC;
        Simple_sorting_by_exchanges_1(array, quantity[r]); // 1 реализация сортировки
        TimeStop = clock()*1000/CLOCKS_PER_SEC;
        
        cpu_time_used = ((double) (TimeStop - TimeStart))/1000;
        res[count] = cpu_time_used;
        count++;

        for(int i = 0; i<quantity[r]-1; i++){if((array[i+1]-array[i])>-1e-6){tmpcount++;}} // Проверка сортировки
    
        if(tmpcount == quantity[r]-1){examination++;}
        tmpcount=0;

        free(array);
    }
    if(examination != 5){fprintf(stderr, "Sort1 - didn't sort the array :("); return 0;} // Проверка 1 реализации

    //

    for (int r=0; r<5; r++)
    {
        tmparray = (double*)malloc(quantity[r] * sizeof(double));
        array = tmparray;

        for(int i = 0; i<quantity[r]; i++){array[i] = ((rand())/((double)(RAND_MAX))) * 2*G - G;}

        TimeStart = clock()*1000/CLOCKS_PER_SEC;
        Simple_sorting_by_exchanges_2(array, quantity[r], cmp_2); // 2 реализация сортировки
        TimeStop = clock()*1000/CLOCKS_PER_SEC;
        
        cpu_time_used = ((double) (TimeStop - TimeStart))/1000;
        res[count] = cpu_time_used;
        count++;

        for(int i = 0; i<quantity[r]-1; i++){if((array[i+1]-array[i])>-1e-6){tmpcount++;}} // Проверка сортировки
    
        if(tmpcount == quantity[r]-1){examination++;}
        tmpcount=0;

        free(tmparray);
    }
    if(examination != 10){fprintf(stderr, "Sort2 - didn't sort the array :("); return 0;} // Проверка 2 реализации сортировки

    //

    for (int r=0; r<5; r++)
    {
        array = (double*)malloc(quantity[r] * sizeof(double));

        for(int i = 0; i<quantity[r]; i++){array[i] = ((rand())/((double)(RAND_MAX))) * 2*G - G;}

        TimeStart = clock()*1000/CLOCKS_PER_SEC;
        Simple_sorting_by_exchanges_3(array, quantity[r], sizeof(double), cmp_3); // 3 реализация сортировки
        TimeStop = clock()*1000/CLOCKS_PER_SEC;
        
        cpu_time_used = ((double) (TimeStop - TimeStart))/1000;
        res[count] = cpu_time_used;
        count++;

        for(int i = 0; i<quantity[r]-1; i++){if((array[i+1]-array[i])>-1e-6){tmpcount++;}} // Проверка сортировки
    
        if(tmpcount == quantity[r]-1){examination++;}
        tmpcount=0;

        free(array);
    }
    if(examination != 15){fprintf(stderr, "Sort3 - didn't sort the array :("); return 0;} // Проверка 3 реализации сортировки

    

    for (int r=0; r<5; r++)
    {
        array = (double*)malloc(quantity[r] * sizeof(double));

        for(int i = 0; i<quantity[r]; i++){array[i] = ((rand())/((double)(RAND_MAX))) * 2*G - G;}

        TimeStart = clock()*1000/CLOCKS_PER_SEC;
        qsort(array, quantity[r], sizeof(double), cmp_qsort); // сортировка qsort
        TimeStop = clock()*1000/CLOCKS_PER_SEC;
        
        cpu_time_used = ((double) (TimeStop - TimeStart))/1000;
        res[count] = cpu_time_used;
        count++;

        for(int i = 0; i<quantity[r]-1; i++){if((array[i+1]-array[i])>-1e-6){tmpcount++;}} // Проверка сортировки
    
        if(tmpcount == quantity[r]-1){examination++;}
        tmpcount=0;

        free(array);
    }
    if(examination != 20){fprintf(stderr, "qsort - didn't sort the array :("); return 0;} // Проверка qsort

    //

    tabl(res);
    if(examination == 20){printf("All arrays are sorted");}
    return 0;
 
}