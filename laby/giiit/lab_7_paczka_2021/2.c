#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void print_tab_all(int y,int a[][y], int x);

void swap_tab(int *a, int *b, int size)
{
    for(int i = 0; i < size; i++)
        swap(a+i,b+i);

}



void swap_row(int n, int (*a)[n], int x, int y)
{

    swap_tab( *(a+x), *(a+y), n);

}
void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
        printf ("\n");    
  }


int main(void)
{

    int tab_1[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4};
    int tab_31[4][5] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,0,0};

    //zamiana całej taqblicy
    for(int i = 0; i < 4; i++ )
        swap_tab(tab_1[i], tab_31[i], 5);


    
    //print_tab_all(5,tab_1,4);
    //printf("\n");
    //print_tab_all(5,tab_3,4);
    
    for(int i = 0; i < 4; i++ )
        swap_tab(tab_1[i], tab_31[i], 5);

    //zadanie:::
    //a
    swap_row(5,tab_1,0,1);
    print_tab_all(5,tab_1,4);
    printf("\n");

    //b
    int tab_2 [5][2] = {1,1,2,2,3,3,4,4,5,5};
    swap_tab(tab_2[0], tab_2[1], 2 );
    print_tab_all(2,tab_2,5);
    //c
    int **tab_3 = malloc( 6*sizeof(int*));
    
    for(int i = 0; i < 6; i++)
        tab_3[i] = malloc(3 * sizeof(int)); //tab_3[6][3]
    
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tab_3[i][j] = rand() % 21;
            printf("%d ", tab_3[i][j] );
        }
        printf("\n");
    }

    printf("\n");
    swap_tab(tab_3[0], tab_3[4], 3);
    
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", tab_3[i][j] );
        }
        printf("\n");
    }

    printf("\n");
    // D
    int **tab_33= malloc( 6*sizeof(int*));

    tab_33[0] = malloc(6*3 * sizeof(int));
    
    for(int i = 1; i < 6; i++)
        tab_33[i] = tab_33[i-1]+3;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            tab_33[i][j] = i;//rand() % 21;
            printf("%d ", tab_33[i][j] );
        }
        printf("\n");
    }

    swap_tab(tab_33[1], tab_33[3], 3);
    printf("\n");

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", tab_33[i][j] );
        }
        printf("\n");
    }


    for(int i = 0; i < 6; i++)
        free(tab_3[i]);
    for(int i = 0; i < 6; i++)
        free(tab_33[i]);

    free(tab_3);
    free(tab_33);
    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void print_tab_all(int y,int a[][y], int x)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");   
    }

}