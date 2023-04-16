#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Program losuje n razy (podane jako argument funkcji main) dwie liczby zmiennoprzecinkowe  z zakresu -1 do 1 oraz sprawdza czy ich suma kwadratów jest mniejsza czy większa od 1. Jaki jest stosunek liczba spełniający ten warunek do n? Niech program który  ten stosunek.  (Uwaga dla dużych n powinno to być pi)*/




double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}




int main(int argc, char* argv[])
{
    srand(time(0));
    double a, b, suma;
    int n=atoi(argv[1]);
    
    
    for(int i=1;i<=n;i++){
        
        a = d_rand(-1.,1.);
        b = d_rand(-1.,1.);
        //printf("%lf ",a);
        suma = a*a+b*b;
        //printf("%lf ",suma);
        if(suma<1){
        printf("Suma wieksza od 1\n");
        
        
        }
    }
    

    return 0;
}
