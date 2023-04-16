#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
double d_rand(double min, double max){
	double r = (double) rand()/RAND_MAX;
	return r*(max-min) + min;
}

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
}


int main(int argc, char* argv[])
{
       srand(time(0));
    int j = atoi(argv[1]),kierunek, n;
    double odleglosc;
    double pol[j];
    pol[0] = 0;
    printf("krok %d polozenie %d\n",0,0);
    for(int i = 1; i<j;i++)
        {
            odleglosc = d_rand(0.25,1);
            n = i_rand(-1,1);
            kierunek = n/abs(n);
            pol[i+1] = pol[i] + kierunek*odleglosc;
            printf("krok %d polozenie %f \n",i,pol[i+1]);
        }


    return 0;
}
