#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void swap_tab(int *a, int *b, int size);
void swap_row(int n, int (*TAB)[n], int x, int y);
void wypisz_i (int *poczatek, int *koniec);


int main(void)
{

    int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    int tab_22[5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};

    
    swap_row(5,tab_1,0,2);
    for(int i = 0; i < 4; i++)
        wypisz_i(tab_1[i], tab_1[i] + 5);

    printf("\n");

    swap_tab(tab_22[0], tab_22[1], 2 );
    
    for(int i = 0; i < 4; i++)
        wypisz_i(tab_22[i], tab_22[i] + 2);

    printf("\n");
    
    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void swap_tab(int *a, int *b, int size)
{
    for(int i = 0; i < size; i++)
        swap(a+i,b+i);

}

void swap_row(int n, int (*TAB)[n], int x, int y)
{

    swap_tab( *(TAB+x), *(TAB+y), n);

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