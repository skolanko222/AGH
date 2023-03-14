#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max);

int main(void)
{
    srand(time(0));
    int rows = i_rand(3,7), columns = i_rand(3,4);

    printf("\nRows: %d Col: %d \n\n", rows,columns);
    
    //inicjalizacja array_1
    int **array_1 = malloc(sizeof(int*) * rows);

    for(int i = 0; i < rows; i++)
    {

        array_1[i] = malloc(sizeof(int) * columns);

    }

    //inicjalizacja array_2
    int (*array_2)[columns] = malloc(sizeof(int*) * rows * columns);
    
    //wypełnienie arr1 liczbami
    for(int i = 0; i < rows; i++)  
        for(int j = 0; j < columns; j++)
        {
            array_1[i][j] = i_rand(1,15);
            array_2[i][j] = i_rand(1,15);
        }

    //wypisanie arr1
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
            printf("Arr1[%2d][%2d] = %d " ,i,j, array_1[i][j]);
        printf("\n");
    }

    printf("\n");

    //wypisanie arr2
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
            printf("Arr2[%2d][%2d] = %d " ,i,j, array_2[i][j]);
        printf("\n");
    }

    int rows_new = i_rand(3,7);

    printf("\n\n\nTe nowe tablice: row: %d\n\n\n\n", rows_new);
	

    //if(rows_new > rows)
    //{
        
        array_1 = realloc(array_1, sizeof(int*) * rows_new);
        array_2 = realloc(array_2, sizeof(int) * rows_new*columns);
        //arr1 v2
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
        array_2 = realloc(array_2,  sizeof(int)*(rows_new*columns));            
        for(int i = rows; i < rows_new; i++)  
        {
            for(int j = 0; j < columns; j++)
            {
            array_2[i][j] = i_rand(1,15);
            }
        }
        
    

    //}
    printf("\n\n");
     //wypisanie arr1 v2
    for(int i = 0; i < rows_new; i++)
    {
        for(int j = 0; j < columns; j++)
            printf("Arr1[%2d][%2d] = %d " ,i,j, array_1[i][j]);
        printf("\n");
    }

    printf("\n");

    //wypisanie arr2 v2
    for(int i = 0; i < rows_new; i++)
    {
        for(int j = 0; j < columns; j++)
            printf("Arr2[%2d][%2d] = %d " ,i,j, array_2[i][j]);
        printf("\n");
    }
    free(array_1);
    free(array_2);
    return 0;
    
}

int i_rand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}