#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void wypisz_i (int *poczatek, int *koniec);
int i_rand(int min, int max);
int suma (int *tab, int len);
int raw_number(int (*tab)[4], int sx);
int *find_min_wsk (int *T_F, int *T_L);
int *fun_find(int (*tab)[4], int sx);

int main(void)
{
    srand(time(0));
    
    //podpunkt a **********************
    
    int abc[5][4];
    for(int i=0; i<5; i++) //WYPELNIANIE TABLICY LICZBAMI LOSOWYMI
    {
        for(int j=0; j<4; j++)
        {
            abc[i][j]=i_rand(-10, 10);
        }
    }

    for(int i=0; i<5; i++) //WYPISYWANIE TABLICY
    {
        wypisz_i(abc[i], abc[i]+4);
    }

    //podpunkt b **********************

    int suma_abc[5] = {0};
    for(int i=0; i<5; i++) //  LICZENIE SUMY
    {
        suma_abc[i]=suma(abc[i], 4);
    }
    printf("\nSuma: ");
    wypisz_i(suma_abc, suma_abc+5); //WYPISYWANIE SUMY

    //podpunkt c **********************

    int suma_all_1 = suma(&abc[0][0], sizeof(abc)/sizeof(int));
    int suma_all_2 = suma(suma_abc,sizeof(suma_abc)/sizeof(int));
    printf("Sumy: %d, %d\n", suma_all_1, suma_all_2);

    //podpunkt d **********************

    int numer_wiersza = raw_number(abc, 5);
    printf("Numer wiersza z minimalna wartoscia: %d\nWiersz z najmniejsza wartoscia: ", numer_wiersza);
    wypisz_i(abc[numer_wiersza], abc[numer_wiersza]+4);
    //printf("\n");

    //podpunkt e **********************

    int* min_wsk = fun_find(abc, 5);
    int licznik=0;
    int * wlicznik = &abc[0][0];
    while(wlicznik<=min_wsk)
    {
        licznik++;
        wlicznik++;
    }
    int szukany_wiersz = ceil(licznik/5);
    int szukana_kolumna = ceil(licznik/4) ;
    printf("Wiersz szukanej najmniejszej wartosci: %d, kolumna %d\n", szukany_wiersz, szukana_kolumna);

    return 0;
}

void wypisz_i (int *poczatek, int *koniec)
 { 
    while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
     printf ("\n");    
}

int i_rand(int min, int max)
{
	return rand() % (max-min+1) + min;
}

int suma (int *tab, int len) 
{ 
    int ss = 0;
    for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
    return ss;
}

int raw_number(int (*tab)[4], int sx)
{
    int minim = tab[0][4];
    int minim_w=0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(tab[i][j]<minim)
            {
                minim=tab[i][j];
                minim_w=i;
            }
        }
    }
    return minim_w;
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

int *fun_find(int (*tab)[4], int sx)
{
    int minim_wiersze[sx];
    
    for(int i=0; i<sx; i++)
    {
        minim_wiersze[i] = *find_min_wsk(tab[i], tab[i]+4);
    }

    int p=minim_wiersze[0];
    int nmr_w=0;
    for(int i=0; i<sx; i++)
    {
        if(minim_wiersze[i]<p)
        {
            p=minim_wiersze[i];
            nmr_w=i;
        }
    }

    return find_min_wsk(tab[nmr_w], tab[nmr_w]+4);
}