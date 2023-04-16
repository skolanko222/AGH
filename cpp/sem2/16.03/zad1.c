#include <stdio.h>
#include <time.h>

void wypelnij(double (*arr)[], int wiersz);

void wypisz_d (double *poczatek, double *koniec) 
    { 
  while (poczatek < koniec) 
    printf ("%6.1f,", *poczatek++); 
  printf ("\n");    
  return;
  
  }


int main(void)
{
    srand(time(0));
    double A_1[8][6], A_2[10][6];

    wypelnij(A_1,8);
    wypelnij(A_2,10);
    
    wypisz_d(*A_1,*(A_1 + 7)+6);
    
    printf("\n");
    
    for(int i = 0; i<8; i++)
    {
        wypisz_d(*(A_1+i),*(A_1 + i)+6);

    }

    printf("\n");

    wypisz_d(*A_2,*(A_2 + 9)+6);

    printf("\n");

    for(int i = 0; i<10; i++)
    {
        wypisz_d(*(A_2+i),*(A_2 + i)+6);

    }


    return 0;
}

void wypelnij(double (*arr)[6], int wiersz)
{
    double temp = 1;//(double )rand();
    double (*tab)[6] = arr;
    for(;tab < arr+wiersz; tab++)
        for(int i = 0; i < 6; i++)
        {
            (*tab)[i] += temp;
            temp += 0.4;

        }



}