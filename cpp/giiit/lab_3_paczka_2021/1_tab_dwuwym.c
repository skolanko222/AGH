#include <stdio.h>

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
        printf ("\n");    
  }

int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;
 
 }

int suma_wsk (int *tab, int *len) { 
  int ss = 0;
  for (int *i = tab; i <= len; i++)  
    ss+= *i; 
 return ss;
 
 }

int *find_max_wsk (int *T_F, int *T_L)
{
    int *max = T_F++;
    while (T_F <= T_L)
    {
        if(*max < *T_F) max = T_F;
        T_F++;
    }
    return max;
}

int *find_min_wsk (int *T_F, int *T_L)
{ 
    int *min = T_F++;
    while (T_F <= T_L)
    {
        if(*min > *T_F) min = T_F;
        T_F++;
    }

    return min;
}

int main(void)
{

    int tab[5][4] = {{-450, 0,1,866670},
                     {120, 8,9,12},
                     {3, 0,3,3},
                     {77774,-3,-4,-7},
                     {0, 5,0,-435}};
    int suma_abc[5] = {0};

    for(int i = 0; i <= 4; i++)
    {
        wypisz_i(&tab[i][0], &tab[i][3]+1);
        printf("\n");

        suma_abc[i] = suma(&tab[i][0],4);
    }

    printf("Suma poszczegolnych wierszy: \n");
    wypisz_i(suma_abc, suma_abc + 5);

    int suma_all = suma(&tab[0][0], sizeof(tab)/sizeof(int));
    int suma_all_abc = suma(suma_abc,sizeof(suma_abc)/sizeof(int));

    printf("\n %4d  %3d",suma_all, suma_all_abc);

    int rozmiar = sizeof(tab)/sizeof(int);
    int ilosc_kolumn = sizeof(tab[0])/sizeof(int);
    int ilosc_wierszy = (sizeof(tab)/sizeof(int))      /       (sizeof(tab[0])/sizeof(int));

    int wiersz_max = (find_max_wsk(&tab[0][0], &tab[0][0] + sizeof(tab)/sizeof(int) - 1) - tab[0]) / (sizeof(tab[0])/sizeof(int)); //UWAGA
    int kolumna_max = (find_max_wsk(&tab[0][0], &tab[0][0] + sizeof(tab)/sizeof(int) - 1) - tab[0]) % ilosc_kolumn; //UWAGA

    printf("\nNumer wiersza z max wartoscia: %d \n", wiersz_max);
    printf("Numer kolumny z max wartoscia: %d \n", kolumna_max);
    printf("Wartosci wiersza %d:\n", wiersz_max);
    wypisz_i(&tab[wiersz_max][0],&tab[wiersz_max][3]+1);

    int *min = find_min_wsk(tab[0], &tab[4][3]);
    int wiersz_min = (min - tab[0]) / (sizeof(tab[0])/sizeof(int));

    printf("\nNumer wiersza z min wartoscia: %d \n", wiersz_min);
    
    
    int kolumna_min = (min - tab[0]) % ilosc_kolumn;
    printf("Numer kolumny z min wartoscia: %d \n\n", kolumna_min);

    int kol, wiersz, *min2; 

    for(int i = 0; i < ilosc_wierszy; i++)
    {
        min2 = find_min_wsk(tab[i], &tab[i][3]);
        wiersz = (min2 - tab[0]) / (sizeof(tab[0])/sizeof(int));
        kol = (min2 - tab[0]) % ilosc_kolumn;
        printf("Minimalny wsk: %p, wiersz: %d, kolumna: %d, wartosc: %d \n",min, wiersz,kol,*min2);
    }
    
    return 0;
}