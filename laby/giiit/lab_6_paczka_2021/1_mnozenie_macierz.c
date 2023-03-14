#include <stdio.h>
#include <stdlib.h>

int **multi_tab(int arr1[][3], int arr2[][4], int wiersze_A, int kolumny_B, int wiersze_B)
{   
    int **arr3 = calloc(wiersze_A,sizeof(int));
    for(int i = 0; i < wiersze_A; i++)
    {

        arr3[i] = calloc(kolumny_B,sizeof(int *));

    }

    for (int i = 0; i < wiersze_A; i++)
    {
        for (int j = 0; j < kolumny_B; j++)
        {
            
            for (int k = 0; k < wiersze_B; k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    return arr3;
}

int **multi_tab_all( int wiersze_A, int wiersze_B, int kolumny_B, int arr1[][wiersze_B], int arr2[wiersze_B][kolumny_B])
{   
    int **arr3 = calloc(wiersze_A,sizeof(int));
    for(int i = 0; i < wiersze_A; i++)
    {

        arr3[i] = calloc(kolumny_B,sizeof(int *));

    }

    for (int i = 0; i < wiersze_A; i++)
    {
        for (int j = 0; j < kolumny_B; j++)
        {
            
            for (int k = 0; k < wiersze_B; k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    return arr3;
}

int main(void)
{
    int tab_A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int tab_B[3][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};

    int wiersze_A = sizeof tab_A / sizeof *tab_A;
    int kolumny_A = sizeof tab_A / (wiersze_A * sizeof(int)); 

    int wiersze_B = sizeof tab_B / sizeof *tab_B;
    int kolumny_B = sizeof tab_B / (wiersze_B * sizeof(int));

    //printf("wiersze: %d kolumny: %d", wiersze, kolumny_B );

    int **result = multi_tab(tab_A, tab_B, wiersze_A, kolumny_B, wiersze_B);
    int **result_2 = multi_tab_all(wiersze_A,wiersze_B,kolumny_B,tab_A,tab_B);

    for(int i = 0; i < wiersze_A; i++)
    {
        for(int j = 0; j < kolumny_B; j++)
        {
            printf("TAB[%d][%d] = %d ",i,j,result_2[i][j]);
            
        }
        printf("\n");

    }

    free(result);

    return 0;
}