#include "header.h"

double Taylor_sin(double x, double eps)
{
    double res1 = 0, res2 = 1, fact=1;
    int i=0;
    while (fabs(res1-res2)>eps && i<20)
    {
        res2=res1;
        res1+=(pow((-1), i) * pow(x, 2*i+1))/fact;
        i++;
        fact*=(2*i)*(2*i+1);
        printf("%lf %lf\n", res1, fact);
    }
    return res1;
}

double Taylor_cos(double x, double eps)
{
    double res1 = 0, res2 = 1, fact=1;
    int i=0;
    while (fabs(res1-res2)>eps && i<20)
    {
        res2=res1;
        res1+=(pow((-1), i) * pow(x, 2*i))/fact;
        i++;
        fact*=(2*i-1)*(2*i);
        printf("%lf %lf\n", res1, fact);
    }
    return res1;
}

double Taylor_exp(double x, double eps)
{
    double res1 = 0, res2 = 1, fact=1;
    int i=0;
    while (fabs(res1-res2)>eps && i<20)
    {
        res2=res1;
        res1+=pow(x, i)/fact;
        i++;
        fact*=i;
        printf("%lf %lf\n", res1, fact);
    }
    return res1;
}

double Taylor_log(double x, double eps)
{
    double res1 = 0, res2 = 1;
    int i=0;
    if(x>1){x = x-1;}
    else if(x>0 && x<1){x = (1-x)/(1+x);}
    else {return -1;}
    while (fabs(res1-res2)>eps && i<20)
    {
        res2=res1;
        res1+=(pow((-1), i)*pow(x, i+1))/(i+1);
        i++;
    }
    return res1;
}