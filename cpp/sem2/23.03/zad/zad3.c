#include <stdio.h>
#include <stdlib.h>

#define K 5
#define W 6
int suma (int *tab, int len)
{ 
    int ss = 0;
    for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
    return ss;
}

void wypisz_i (int *poczatek, int *koniec) 
{ 
    while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
    printf ("\n");    
    return;
}

float *tab_avg(int (*arg)[K], int (*arg2)[K])
{
    int wiersze = arg2 - arg;
    float *p = malloc(wiersze*sizeof(float));

    for(int i = 0; i <= wiersze; i++)
    {

        p[i] = suma(arg[i],K) / 5.;

    }


    return p;
}

void wypisz_f (float *poczatek, float *koniec) { 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;}

int main(void)
{
    int TAB[W][K] = {{1,2,3,4,5},
                     {1,2,3,4,6},
                     {1,2,3,4,7},
                     {1,2,3,4,8},
                     {1,2,3,4,9},
                     {1,2,3,4,0}};
    for(int i = 0; i < W; i++)
    {

        wypisz_i(*(TAB+i),*(TAB+i) + K);

    }

    float *q = tab_avg(TAB,TAB+W);

    printf("Srednie: ");
    wypisz_f(q,q + W);

    free(q);

    return 0;
}