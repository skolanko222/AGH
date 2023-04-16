#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define K 10
#define W 5

int suma (int *poczatek, int *koniec) 
{
    int ss = 0;
    while (poczatek < koniec)
    ss+= *poczatek++;
    return ss;
}

void wypisz_i (int *poczatek, int *koniec)
{ 
    while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
    printf ("\n");    
}

double *tab_avg(int (*start)[K])
{
    double *res = malloc(W*sizeof(double));

    for(int i = 0; i < W; i++)
    {

        res[i] = suma(start[i],start[i]+K);

    }

    return res;
}


int main(void)
{
    srand(time(0));
    int TAB[W][K];

    for(int *p = *TAB; p < *TAB + W*K; p++)
        *p = rand() % 11 -5;
    for(int i = 0; i < W; i++)
        wypisz_i(TAB[i],TAB[i] + K);

    double *ress = tab_avg(TAB);


    for(int j = 0; j < W; j++)
        printf("Srednia %d: %lf\n",j,ress[j]);

    return 0;
}