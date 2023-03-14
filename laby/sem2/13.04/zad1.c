#include <stdio.h>
void swap(int*a, int*b);
void wypisz_i (int *poczatek, int *koniec);

void swap_tab(int *A, int *B, int n);
void swap_rows(int n, int (*TAB)[n], int x, int y);


int main(void)
{
    int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};

    swap_rows(5, tab_1, 0, 2);
    for(int i = 0; i < 4; i++)
        wypisz_i(tab_1[i],tab_1[i]+5);

    printf("\n");

    swap_tab(tab_22[0],tab_22[1], 2);
    for(int i = 0; i < 4; i++)
        wypisz_i(tab_22[i],tab_22[i]+2);

    return 0;
}
void swap_tab(int *A, int *B, int n)
{

    for(int i = 0; i < n; i++)
    {
        swap(A+i,B+i);
    }

}

void swap_rows(int n, int (*TAB)[n], int x, int y)
{

   swap_tab(TAB[x],TAB[y], n);

}

void swap(int*a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void wypisz_i (int *poczatek, int *koniec) 
{ 
  while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
  printf ("\n");    
  return;
}