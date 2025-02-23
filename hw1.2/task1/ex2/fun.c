#include "header.h"

double rectangle (double (*f)(double), double a, double b, double eps, int *Tmp)
{
    int n=5, cnt=0;
    double res1=0, res2=-10, tmp=0;

    if(errors(a, b, eps, Tmp) != 1)  // проверка ошибок
    {
        return -1;
    }

    while (fabs(res2-res1) > eps)
    {
        res1 = res2;
        res2=0;
        tmp = (b-a)/n;
        for(int i=0; i<n; i++)
        {
            res2 += f(a+tmp*i)*tmp;
            cnt++;
        }
        if(cnt>10e7)
        {
            Tmp[1] = 3; // Слишком много итериций
            return -1;
        }
        n*=2;       
    }
    Tmp[0] = cnt;
    return res2;
}

double trapezoid (double (*f)(double), double a, double b, double eps, int *Tmp)
{
    int n=2, cnt=0;
    double res1=0, res2=-10, h=0, tmp2=f(a), tmp1;

    if(errors(a, b, eps, Tmp) != 1)  // проверка ошибок
    {
        return -1;
    }

    while (fabs(res2-res1) > eps)
    {
        res1 = res2;
        res2=0;
        h = (b-a)/n;
        for(int i=1; i<n; i++)
        {
            tmp1 = f(a+h*i);
            res2 += (tmp2+tmp1)/2*h;
            tmp2 = tmp1;
            cnt++;
        }
        if(cnt>10e7)
        {
            Tmp[1] = 3; // Слишком много итериций
            return -1;
        }
        n*=2;
        
    }
    Tmp[0] = cnt;
    return res2;
}

double Simpson (double (*f)(double), double a, double b, double eps, int *Tmp)
{
    int n=2, cnt=0;
    double res1=0, res2=-10, h=0, c = (a+b)/2;
    double fa = f(a), fb = f(b), fc = f(c);
    double tmpa=a, tmpb=b;

    if(errors(a, b, eps, Tmp) != 1)  // проверка ошибок
    {
        return -1;
    }

    while (fabs(res2-res1) > eps)
    {
        res1 = res2;
        res2=0;
        
        h = (b-a)/n;
        for(int i=1; i<n+1; i++)
        {
            tmpb=a+h*i;

            fc = f((tmpa + tmpb)/2);
            fb = f(tmpb);
            
            res2+= ((tmpb - tmpa)/6) * (fa + 4*fc + fb);
            fa = fb;
            tmpa=tmpb;
            cnt++;
        }
        tmpa = a;
        tmpb = b;

        if(cnt>10e7)
        {
            Tmp[1] = 3; // Слишком много итериций
            return -1;
        }
        n*=2;    
    }
    Tmp[0] = cnt;
    return res2;
}


double Gauss (double (*f)(double), double a, double b, double eps, int *Tmp)
{
    int n=2, cnt=0;
    double res1=0, res2=-10, h=0, c, k;
    double tmpa=a, tmpb=b;
    double A = 2*sqrt(3);

    if(errors(a, b, eps, Tmp) != 1)  // проверка ошибок
    {
        return -1;
    }

    while (fabs(res2-res1) > eps)
    {
        res1 = res2;
        res2=0;
        
        h = (b-a)/n;
        for(int i=1; i<n+1; i++)
        {
            tmpb=a+h*i;

            c = (tmpa + tmpb)/2;
            k = (tmpb - tmpa)/A;
            
            res2+= (tmpb - tmpa)/2 * (f(c - k)+f(c + k));

            tmpa=tmpb;
            cnt++;
        }
        tmpa = a;
        tmpb = b;
        if(cnt>10e7)
        {
            Tmp[1] = 3; // Слишком много итериций
            return -1;
        }
        n*=2;   
    }
    Tmp[0] = cnt;
    return res2;
}

int errors(double a, double b, double eps, int *Tmp)
{
    if((a-b)>eps) 
    {
        Tmp[1] = 1; // Некорректный отрезок
        return -1;
    }

    if(eps < 0) 
    {
        Tmp[1] = 2; // Некорректный ввод eps
        return -1;
    }

    return 1;
}