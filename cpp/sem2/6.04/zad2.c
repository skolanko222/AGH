#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_tab_all(int y,int a[][y], int x);
int i_rand(int, int);
int (*trans_tab_all(int row, int col, int arr[row][col]))[ ];



int main(void)
{
    srand(time(NULL));

    int tab_A [2][3] = {{1,2,3},{4,5,6}};
    int tab_B [3][4] = {{1,6,1,44},{31,21,1,7},{1,15,13,1}};

    print_tab_all(3, tab_A, 2);
    printf("\n");
    print_tab_all(4, tab_B, 3);

    int (*trans_A)[3] = trans_tab_all(2, 3, tab_A);
    int (*trans_B)[4] = trans_tab_all(3, 4, tab_B);

    printf("\n");

    print_tab_all(2, trans_A, 3);
    printf("\n");
    print_tab_all(3, trans_B, 4);

    free(trans_A);
    free(trans_B);

    return 0;
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

int i_rand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
int (*trans_tab_all(int row, int col, int arr[row][col]))[]
{

    int (*tra)[row] = calloc(row*col,sizeof(int));

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            tra[j][i] = arr[i][j];

    return tra;
}