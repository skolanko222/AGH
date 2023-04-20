#include <stdio.h>
#include <stdlib.h>

int icmpr ( const void *a, const void *b);
void wypisz_i (int *poczatek, int *koniec);

void all(int row, int col, int tab_A[row][col], int *key);

int main(void)
{
    int tab_A[3][6] = {{69,45,23,6,2137,345},{1,45,23,6,3,3},{1,79,23,6,3,-3}};
    int tab_B[4][5] = {{69,45,23,6,123},{1,45,23,6,3},{1,79,23,6,3},{1,2137,23,6,3}};
    int key = 2137;

    all(3,6,tab_A,&key);
    all(4,5,tab_B,&key);
    
    return 0;
}

int icmpr ( const void *a, const void *b)
{
    return *( const int *)a - *( const int *)b;
}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
        printf ("\n");    
  }
void all(int row, int col, int tab_A[row][col], int *key)
{
    qsort(tab_A, row*col, sizeof(int), icmpr);

    for(int i = 0; i < row; i++)
        wypisz_i(tab_A[i],tab_A[i] + col);

    int *p = bsearch(key, tab_A, row*col, sizeof(int), icmpr);
    
    if(p == NULL)
    {
        printf("Nie znaleniono.\n");
        printf ("\n");
    }
    
    else
    {
        int wiersz = (p - &tab_A[0][0]) / col; 

        printf("Znaleniono w wierszu nr: %d \n",wiersz);
        wypisz_i(tab_A[wiersz],tab_A[wiersz]+col);
        printf ("\n");
    }

}