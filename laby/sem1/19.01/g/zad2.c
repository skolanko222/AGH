#include <stdio.h>
#include <stdlib.h>

/*Napisz funkcje która pobiera tablice o długości n oraz liczbę k. Funkcja uzupełnia kolejne elementy tablic średnią z danego elementu oraz z k poprzednich elementów. 

Uwaga aby to zrobić warto posłużyć się  tablicą pomocnicza aby do obliczeń średniej dla i-tego elementu brać zawsze oryginalne elementy tablicy wejściowej, a nie wcześniej obliczoną średnią która jest w elemencie np i-1. Tablica pomocnicza nie jest jednak niezbędna. 

Należy przynajmniej raz poprawnie użyć funkcji w programie.

Przykład dla k=1

tablica wejściowa [1, 2,   3,   4,   5,   4] 
tablica wyjściowa [1, 1.5, 2.5, 3.5, 4.5, 4.5]*/


void wypisz_srednia_tab(float tab2[], int k, int w_tab2);

int main()
{
    float tab1[] = {1,2,3,4,5,4};
    int k=1; // ilosc poprzednich elementow
    int w_tab1 = sizeof(tab1)/sizeof(tab1[0]);

    wypisz_srednia_tab(tab1,k,w_tab1);
    
    for(int i=0;i<w_tab1;i++)
    {
    
        printf("%f ",tab1[i]); //testowe wypisanie
    
    }


    return 0;
}

void wypisz_srednia_tab(float tab2[], int k, int w_tab2)
{
    float t_wynik[w_tab2];

    float suma;

    int l=0;

    //przepisywanie wartosci dla ktorych srednia nie istnieje
    for(l=0;l<k;l++)
        t_wynik[l] = tab2[l];

    for(;l<w_tab2;l++)
    {
        suma=0;
        for(int i=0;i<=k;i++) //cofanie sie o k miejsc + l-ta liczba
        {
            suma+=tab2[l-i];
        }
        t_wynik[l]=suma/(k+1);
    }
    
    for(int i=0; i<w_tab2; i++)
    {
    
        tab2[i] = t_wynik[i]; //przepisanie
        
    }
   
}
