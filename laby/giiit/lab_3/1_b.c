#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wypelnij(double (*tab)[6], int sx);
double d_rand(double min, double max);
void wypisz_d (double *poczatek, double *koniec);

int main(void)
{
    srand(time(0));
    
    double a_1 [8][6];
    double a_2 [10][6];

    wypelnij(a_1, 8);
    wypelnij(a_2, 10);

    
    wypisz_d(a_1[0], a_1[8]);
    printf("\n");
    
    for(int i=0; i<10; i++)
    {
        wypisz_d(a_2[i], a_2[i]+6);
    }

    
    return 0;
}

void wypelnij(double (*tab)[6], int sx)
{
    double losowa = d_rand(10.0,50.0);
    double (*fp)[6] = tab;
    (*fp)[0]=losowa;
    for(; fp<tab+sx; fp++)
    {
        for(int i=0; i<6; i++)
        {
            (*fp)[i]=losowa+0.4;
            losowa+=0.4;
        }
    }

}

double d_rand(double min, double max)
{
	double r = (double) rand()/RAND_MAX;
	return 1;
}

void wypisz_d (double *poczatek, double *koniec) 
{ 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;
}