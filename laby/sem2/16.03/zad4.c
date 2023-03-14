#include <stdio.h>
void wypisz_i (int *poczatek, int *koniec) { 

    int i = 0, j = 0;
  while (poczatek < koniec)
  {
    printf ("TAB[%d][%d] = %4d ",i,j, *poczatek++);

    j == 4 ?  printf("\n") && ++i && (j=0) : j++;


  }
       
  printf ("\n");    
  
  return;}

void swap(int*a, int*b){
         int temp = *a;
         *a = *b;
         *b = temp;
         return;}




void wypelnij(int (*arr)[5], int dl);
void transponowanie(int (*arr)[5], int dl);
void nad(int (*arr)[5]);


int main(void)
{
    int tab[5][5];//= {{1},{2},{3}};

    int ile_wierszy = sizeof(tab) / sizeof(int) / 5;

   // printf("%d", ile_wierszy);
    wypelnij(tab,ile_wierszy);
    wypisz_i(*tab, *tab + (ile_wierszy*5));
    transponowanie(tab,ile_wierszy);
    wypisz_i(*tab, *tab + (ile_wierszy*5));


    return 0;
}

void wypelnij(int (*arr)[5], int dl)
{
   // int (*p)[5] = arr;
    for(int i = 0 ; i < dl; i++ )
        for(int j = 0; j < 5;j++)
        {

            arr[i][j] = i;

        }


}

void transponowanie(int (*arr)[5], int dl)
{
    int i = 0, j = 0, k = 0;
    while(i < 5 && j < 5)
    {
        swap(*(arr + i)+j, *(arr+j) + i);
        i == 4 ? ++j && (i = 1+k) && ++k: i++;


    }




}
void nad(int (*arr)[5]) //niedokonczone
{


}