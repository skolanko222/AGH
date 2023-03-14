#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max);

int main(void)
{
    //*********************************************A
    srand(time(0));
    int rows = i_rand(3, 7);
    int columns = i_rand(3, 7);

    //*********************************************B
    //array 1
    int **array_1 = malloc(rows*sizeof(int*));
    if(array_1==NULL)
    {
        printf("Blad w alokacji!");
        exit(-1);
    }
    for(int i=0; i<rows; i++)
    {
        array_1[i]=malloc(columns*sizeof(int));
        if(array_1[i]==NULL)
        {
            printf("Blad w alokacji!");
            exit(-1);
        }
    }
    //array 2
    int (*array_2)[columns]=malloc((rows*columns)*sizeof(int));
    if(array_2==NULL)
    {
        printf("Blad w alokacji!");
        exit(-1);
    }

    //*******************************************C
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            array_1[i][j]=i_rand(1, 15);
            array_2[i][j]=i_rand(1, 15);
        }
    }

    //*******************************************D
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            printf("%d\t", array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            printf("%d\t", array_2[i][j]);
        }
        printf("\n");
    }

    //*******************************************E
    int rows_new = i_rand(3, 7);
    printf("\n%d", rows_new);

    //*******************************************F
    //array 1
    array_1 = realloc(array_1, sizeof(int*)*(rows_new));
    for(int i = rows; i <=rows_new; i++)
    {
        array_1[i] = malloc(sizeof(int) * columns);
    }
    for(int i = rows; i < rows_new; i++)  
    {
        for(int j = 0; j < columns; j++)
        {
            array_1[i][j] = i_rand(1,15);
        }
    }
    //array 2
    array_2 = realloc(array_2,  sizeof(int)*(rows_new*columns));            //tu nie działa!!!!!!!!!!!!!1111
    for(int i = rows; i < rows_new; i++)  
    {
        for(int j = 0; j < columns; j++)
        {
            array_2[i][j] = i_rand(1,15);
        }
    }

    //*******************************************G
    printf("\n\n");
    for(int i=0; i<rows_new; i++)
    {
        for(int j=0; j<columns; j++)
        {
            printf("%d\t", array_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<rows_new; i++)
    {
        for(int j=0; j<columns; j++)
        {
            printf("%d\t", array_2[i][j]);
        }
        printf("\n");
    }

    //*******************************************H
    for(int i = 0; i < rows; i++)
    {

        free(array_1[i]);

    }    

    free(array_2);

    return 0;
}

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
}