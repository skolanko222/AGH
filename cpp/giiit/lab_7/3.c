#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COL 5

void proc_1(int row, int col, int arr[][col]);
void proc_2(int row, int col, int arr[][col]);
 int _Funkcja_Poruwnujaca(const void *a, const void *b);
void wypisz_i (int *poczatek, int *koniec);
 int suma(int *poczatek, int *koniec);

int main(void)
{
    int tab_1[ROWS][COL] = {{1,1,34,1,1},{232,2,2,-98,2},{3,3,3,-10,3},{4,4,34443,4,4}};

    proc_1(ROWS, COL, tab_1);

    for(int i = 0; i < ROWS; i++)
        wypisz_i(tab_1[i], tab_1[i] + COL);



    return 0;
}

void proc_1(int row, int col, int arr[][col])
{
    for(int i = 0; i < row; i++)
    {

        qsort(arr[i], col, sizeof(int),_Funkcja_Poruwnujaca);

    }

    
}
void proc_2(int row, int col, int arr[][col])
{
    int suma_w[row];
    int min_licznik;

    for(int i = 0; i < row; i++)
    {
        suma_w[i] = suma(arr[i], arr[i] + col);

    }


}

int _Funkcja_Poruwnujaca(const void *a, const void *b)
{

    return *((const int *) a) > *((const int *) b) ? 1 : -1;

}

int suma(int *poczatek, int *koniec) 
{
    int ss = 0;
    while (poczatek < koniec)
    ss+= *poczatek++;
    return ss;
}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
        printf ("\n");    
  }
