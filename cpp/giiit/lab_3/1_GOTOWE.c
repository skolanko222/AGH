#include <stdio.h>
#include <time.h>

void wypelnij(double (*tab)[6], int);
void wypisz_d (double *poczatek, double *koniec) 
{ 
  while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
  printf ("\n");    
  return;
}

int main(void)
{
    srand(time(0));
    double A_1[8][6], A_2[10][6];

    wypelnij(A_1,8);

    wypelnij(A_2,10);

    for(int i = 0; i<=7; i++)
        wypisz_d(A_1[i],A_1[i]+6); // WYPISZ WIERSZE

    printf("\n");

    for(int i = 0; i<=9; i++)
        wypisz_d(A_2[i],A_2[i]+6); // WYPISZ WIERSZE

}

void wypelnij(double (*tab)[6], int wiersz)
{
    double temp = 1.0;
    double (*p)[6] = tab;
    for(; p < tab + wiersz; p++)
    {   

        for(int i = 0; i <= 5 ; i++)
        {
            (*p)[i] = temp;
            temp+=0.4;
        }
        
    }


}