#include <stdio.h>
#include <math.h>

double pizda(double x)
{
    return -x*x + 3*x + 11;
}

int zero(double (*f)(double), double a, double b, double eps_x, double eps_y)
{   
    double f_a = f(a);
    
    double f_b = f(b);

    if(f_a*f_b >= 0) //bo przedział musi być -/+ lub +/-
        return -1;
    double c = (a+b)/2;
    if(fabs(a-c) < eps_x) //dokladosc x
    {
        printf("M_Z: %lf",c);
        return 1;
    }

    double f_c = f(c);
    
    if(fabs(c) < eps_y) //dokladosc y
    {
        printf("M_Z: %lf",c);
        return 1;
    }

    if(f_c*f_a < 0)
        zero(f,a,c,eps_x,eps_y); //jak za mala dokladnosc to nowy przedział
    else
    
        zero(f,c,b,eps_x,eps_y);
}

int main(void)
{
    double a = zero(sin, 1, 4, 0.0000001, 0.00000001);
    printf("\n\n%d",a);

    return 0;
}