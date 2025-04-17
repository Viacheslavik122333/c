#include "header.h"

int main(void)
{
    double res;
    res = Taylor_sin(3.1415/2, 1e-12);
    printf("sin = %lf\n", res);

    res = Taylor_cos(3.1415/2, 1e-12);
    printf("cos = %lf\n", res);

    res = Taylor_exp(2, 1e-9);
    printf("exp = %lf\n", res);

    res = Taylor_log(0.9, 1e-9);
    printf("log = %lf\n", res);

    return 0;
}









//     const char *Errors[5];
//     const char* Name_functions[5];
//     double a[10], b[10], eps[10], answer[10];
//     double (*func[10])(double) = {&f1, &f2, &f3, &f4,  &f5,  &f6,  &f7,  &f8, &f9, &f10};
//     int Tmp[2];
//     clock_t TimeStart, TimeStop;

//     setlocale(LC_ALL, "rus");
//     srand(time(NULL));

//     auxiliary_function(eps, answer, Errors, Name_functions, a, b);
    
//     Tmp[0] = 0; // count   
//     Tmp[1] = 0; // error

//     for(int j=0; j<4; j++)
//     {
//         printf("\n\n%s\n", Name_functions[j]);
        
//         for(int i=0; i<10; i++)
//         {
//             TimeStart = clock()*1000/CLOCKS_PER_SEC;
//             res = FUN(j, func[i], a[i], b[i], eps[i], Tmp);
//             TimeStop = clock()*1000/CLOCKS_PER_SEC;

//             if((Tmp[1] == 0) && (fabs(res - answer[i]) < eps[i])) 
//             {
//                 printf("test %d success! (iterations: %d, time: %lf, res = %.12lf) \n", i+1, Tmp[0], ((double) (TimeStop - TimeStart))/1000, res);
//             }
//             else 
//             {
//                 printf("test %d failure! %s :(\n", i+1, Errors[Tmp[1]]);
//                 // printf("test %d failure! %s %d, %.16lf:(\n", i+1, errors[Tmp[1]], Tmp[1], res);
//             }
//             Tmp[0] = 0; // count 
//             Tmp[1] = 0; // error
//         }
//     }
//                     // test 1: f(x) = 3x^2, [0,2], answer = 8, eps = 1e-6 
//                     // test 2: f(x) = 3x^2, [0,2], answer = 8, eps = 1e-9
//                     // test 3: Неправильно задан отрезок [5,2]
//                     // test 4: Неправильно задан eps
//                     // test 5: f(x) = 3x^2, [6,6], answer = 0, eps = 1e-6
//                     // test 6: f(x) = 1/x, [1,8], answer = 3ln(2), eps = 1e-6
//                     // test 7: f(x) = 1/x, [1,8], answer = 3ln(2), eps = 1e-12
//                     // test 8: f(x) = x * cos(x), [0,9], answer = 9*sin(9)+cos(9)-1, eps = 1e-5
//                     // test 9: f(x) = x * cos(x), [1,20], answer = 20*sin(20)+cos(20)-sin(1)-cos(1), eps = 1e-13
//                     // test 10: f(x) = 1/(cos(x)^4), [0,1], answer = pow(tan(1), 3))/3 + tan(1), eps = 1e-6
//     return 0;