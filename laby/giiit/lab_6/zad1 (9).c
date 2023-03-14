#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(void)
{
    srand(time(NULL));

    int rows = i_rand(3,7);
    int columns = i_rand(3,7);


    //inicjalizacja aray1
    int **array_1 = malloc(sizeof(int *) * rows);

    for(int i = 0; i < rows; i++)
    {

        array_1[i] = malloc(sizeof(int) * columns);

    }
    
    //inicjalizacja aray2
    int **array_2 = malloc(sizeof(int *) * rows);

    int * array_3 = malloc(sizeof(int *) * rows * columns);

    for(int i = 0; i < rows; i++)
    {

        array_2[i] = array_3 + i*columns;

    }

    //losowanie wartosci

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
        {
            array_1[i][j] = i_rand(1,15);
            array_2[i][j] = i_rand(1,15);

        }

    //wypisywanie(array_1);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
        printf("arr1[%2d][%2d] = %d ",i,j, array_1[i][j]);
        }

        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
        printf("arr2[%2d][%2d] = %d ",i,j,array_2[i][j]);
        }
        printf("\n");
    }

    //nowy rozmiar
    printf("\n");

    int rows_new = i_rand(3,7);

    printf("Nowy rozmiar: %d", rows_new);
    printf("\n");

    if(rows_new < rows) //gdy nowa jest mniejsza
    {
        
        for(int i = rows_new; i < rows; i++)
        {
            free(array_1[i]);
        }
        

        array_1 = realloc(array_1, sizeof(int *) * rows_new);

        for(int i = 0; i < rows_new; i++)
        {

            array_1[i] = realloc(array_1[i],sizeof(int) * columns);

        }

        array_2 = realloc(array_2, sizeof(int *) * rows_new);
        array_3 = realloc(array_3, sizeof(int ) * rows_new * columns);

        for(int i = 0; i < rows_new; i++)
        {

            array_2[i] = array_3 + i*columns;

        }
        //wypisywanie
        for(int i = 0; i < rows_new; i++)
        {
            for(int j = 0; j < columns; j++)
            {
            printf("arr1[%2d][%2d] = %d ",i,j, array_1[i][j]);
            }

            printf("\n");
        }
        printf("\n");
        for(int i = 0; i < rows_new; i++)
        {
            for(int j = 0; j < columns; j++)
            {
            printf("arr2[%2d][%2d] = %d ",i,j, array_2[i][j]);
            }
            printf("\n");
        }
        //ZWALNIANIE PODPIETYCH DO array_1
        for(int i = 0; i < rows_new; i++)
        {

            free(array_1[i]);

        }


    }
    else
    {
        //powiekszanie
        array_1 = realloc(array_1, sizeof(int *) * rows_new);

        for(int i = 0; i < rows_new; i++)
        {

            array_1[i] = realloc(array_1[i],sizeof(int) * columns);

        }
        
        //powiekszanie
        array_2 = realloc(array_2, sizeof(int *) * rows_new);
        array_3 = realloc(array_3, sizeof(int ) * rows_new * columns);
        //powiekszanie
        for(int i = 0; i < rows_new; i++)
        {

            array_2[i] = array_3 + i*columns;

        }
        //wypelnianie nowych wierszy
        for(int i = rows; i < rows_new; i++)
            for(int j = 0; j < columns; j++)
            {
                array_1[i][j] = i_rand(1,15);
                array_2[i][j] = i_rand(1,15);

            }
        //wypisanie powiekszonych tablic
        for(int i = 0; i < rows_new; i++)
        {
            for(int j = 0; j < columns; j++)
            {
            printf("arr1[%2d][%2d] = %d ",i,j, array_1[i][j]);
            }

            printf("\n");
        }
        printf("\n");
        for(int i = 0; i < rows_new; i++)
        {
            for(int j = 0; j < columns; j++)
            {
            printf("arr1[%2d][%2d] = %d ",i,j, array_2[i][j]);
            }
            printf("\n");
        }
        //ZWALNIANIE PODPIETYCH DO array_1
        for(int i = 0; i < rows_new; i++)
        {

            free(array_1[i]);

        }
    }

    free(array_1);
    free(array_2);
    free(array_3);

    return 0;
}
