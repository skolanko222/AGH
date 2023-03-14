#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 8

void print_tab_all(int y,int a[][y], int x);
int i_rand(int, int);
int (*trans_tab_all(int row, int col, int arr[row][col]))[ ];



int main(void)
{
    srand(time(NULL));
    int TAB[ROW][COL];
    for(int i = 0; i < ROW; i++)  
            for(int j = 0; j < COL; j++)
                TAB[i][j] = i_rand(1,99);

    print_tab_all(COL, TAB, ROW);

    int (*tran)[COL] = trans_tab_all(ROW, COL, TAB);

    printf("\n");

    print_tab_all(ROW, tran, COL);

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
