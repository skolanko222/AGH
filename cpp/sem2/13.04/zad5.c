#include <stdio.h>
#include <math.h>

double w(double x)
{
    return -x*x + 3*x + 11;
}

int zero(double (*f)(double), double a, double b, double *m_z, double eps_x)
{   
    double f_a = f(a);
    
    double f_b = f(b);

    if(f_a*f_b >= 0) 
        return 0;
        
    double c = (a+b)/2;
    double f_c = f(c);

    if(fabs(a-c) < eps_x) 
    {
        *m_z = c;
        return 1;
    }

    if(f_c*f_a < 0)
        zero(f,a,c,m_z,eps_x); 
    else
        zero(f,c,b,m_z,eps_x);

}

int main(void)
{
    double mz;
    
    double a = zero(w, 0, 8, &mz, 0.00001);
    if(a == 0)
        printf("Brak miejsc zerowych!\n");
    else
        printf("Miejsc zerowe: %.2lf \n", mz);

    double b = zero(w, -1, 1, &mz, 0.0001);
    
    if(b == 0)
        printf("Brak miejsc zerowych!\n");
    else
        printf("Miejsc zerowe: %lf\n", mz);       
    
    double c = zero(sin, -1, 1, &mz, 0.000000001);
    
    if(c == 0) //????
        printf("Brak miejsc zerowych!\n");
    else
        printf("Miejsc zerowe: %lf\n", mz);      


    return 0;
}