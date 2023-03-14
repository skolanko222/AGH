#include <stdio.h>
#include <stdlib.h>

int icmpr ( const void *a, const void *b);
void wypisz_i (int *poczatek, int *koniec);
int suma (int *tab, int len);

void all(int row, int col, int tab_A[row][col], int *key);

int main(void)
{
    int tab_A[3][6] = {{1,5},{2},{3}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    int key = 2;

    all(3,6,tab_A,&key);
    all(4,3,tab_B,&key);
    
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
    

    for(int i = 0; i < row; i++)
        wypisz_i(tab_A[i],tab_A[i] + col);

    int suma_a[row];

    for(int i = 0; i < row; i++)
    {

        suma_a[i] = suma(tab_A[i], col);
        printf("%d ", suma_a[i]);

    }

    qsort(suma_a, row, sizeof(int), icmpr);
    wypisz_i(suma_a, row);
    
    int *p = bsearch(key, suma_a, row, sizeof(int), icmpr);
    int index = p - suma_a;

    if(p == NULL)
    {
        printf("Nie znaleniono.\n");
        printf ("\n");
    }
    else
    {
        printf("Znaleziono: \n");
        wypisz_i(tab_A[index],tab_A[index] + col);
        printf ("\n");

    }

    

}
int suma (int *tab, int len) { 
  int ss = 0;
  for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
 return ss;}