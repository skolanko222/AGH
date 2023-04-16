#include <stdio.h>
#include <stdlib.h>

double *find_max_wsk (double *T_F, double *T_L)
{ 

    double *min = T_F++;
    while (T_F < T_L)
    {
        if(*min < *T_F) min = T_F;
        T_F++;
    }

    return min;

}

void wypisz_d (double *t, int len) 
{
    for (int i = 0; i < len; i++)
    printf ("%6.2f", t[i]);
    printf ("\n");
    return;
}

double suma (double *poczatek, double *koniec) 
{
    double ss = 0;
    while (poczatek < koniec)
    ss+= *poczatek++;
    return ss;
}


double suma_Tx(double **poczatek, int kolumna, int dl) 
{
    
    return suma(poczatek[kolumna],  poczatek[kolumna] + dl);;
    
}

double **find_tab(double **arr, int ile)
{
    double wynik[ile];

    for(int i = 0; i < ile; i++)
    {

        wynik[i] = suma_Tx(arr,i,4);
        
    }

    
    return arr + (find_max_wsk(wynik,wynik + ile) - wynik);
}

void swap_pointer(double **arr1, double **arr2)
{
    double *temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;

}

double **find_tab_1(double **arr, int ile)
{
    double wynik[ile];

    for(int i = 0; i < ile; i++)
    {

        wynik[i] = suma_Tx(arr,i,4);
        
    }

    
    return arr + (find_max_wsk(wynik,wynik + ile) - wynik);
}

int main(void)
{
    double T_1[4] = {100.0,3.0, 2.0,1.5};
    double T_2[4] = {1.8, 2.0, 1.2, 3.8};
    double T_3[4] = {5.6, 1.0, 3.3, 3.3};
    double T_4[4] = {1.1, 2.1, -6.5, 1.7};
    double T_5[4] = {6.7, 7.8, 9.1, 1.0};

    double *TAB[5] = {T_1, T_2, T_3, T_4, T_5}; // a)

    for (int i = 0; i < sizeof(TAB)/sizeof(TAB[0]); i++){
        for (int j = 0; j < 4; j++)   
            printf("TAB[%d][%d] = %5.2f ", i, j, TAB[i][j]);
            printf ("\n"); 
    }

    printf ("\nSuma %lf", suma_Tx(TAB, 0, 4)); //b)

    printf("\n");
    
    double **p = find_tab(TAB, 5); //c
   // wypisz_d(*p,4); //c

    swap_pointer(TAB,TAB+1);
    wypisz_d(TAB[0],4);
    wypisz_d(TAB[1],4);
    

    return 0;
}