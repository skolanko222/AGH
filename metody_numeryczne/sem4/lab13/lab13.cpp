#include <stdio.h>
#include <math.h>

int main()
{
    const double a = 1;
    const double b = 1;
    const double c = 1;
    const double d = 1;

    double K = 1;
    double Z = 0.5;

    double t0 = 1;
    double tK = 40;
    double dt = 0.1;

    //Euler
    double t = t0;
    for(double i = t0; i < tK; i+=dt){
        K += dt*(a*K - b*K*Z);
        Z += dt*(c*K*Z -d*Z);
        // t = t + dt;

        // printf("%lf\t%lf\t%lf\n",i,K,Z);
    }

    K = 1;
    Z = 0.5;
    t0 = 1;
    tK = 40;
    dt = 0.1;

    
    for(double i = t0; i < tK; i+=dt){
        double dK1 = dt*(a*K - b*K*Z);
        double dZ1 = dt*(c*K*Z -d*Z);

        double dK2 = dt*(a*(K + dK1/2.0) - b * (K + dK1/2.0) * (Z + dZ1/2.0));
        double dZ2 = dt*(c*(K + dK1/2.0)*(Z + dZ1/2.0) - d* (Z + dZ1/2.0));

        K += dK2;
        Z += dZ2;

        // printf("%lf\t%lf\t%lf\n",i,K,Z);
    }

}
