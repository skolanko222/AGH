#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elastyna1
{
    unsigned char lenght;
    unsigned char numbers[];
}elastyna;

void wypisz(elastyna * el, unsigned char n)
{
    for(int i = 0; i < n; i++) printf("%d",el->numbers[i]);
    printf("\n");
}

int main(void)
{   
    elastyna * arr [5];

    srand(time(NULL));
    unsigned char n = 100;//(rand() % 50) + 100;

    for(elastyna **temp = arr; temp < arr + 5; temp++)
        *temp = malloc(sizeof(elastyna) + n*sizeof(char));

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n; j++)
        {
            if(j == 0) arr[i]->numbers[0] = (rand() % 9) + 1;
            else arr[i]->numbers[j] = rand() % 10;
        } 
        printf("Liczba %d: ",i+1);
        wypisz(arr[i],n);
    }


    for(elastyna **temp = arr; temp < arr + 5; temp++)
        free(*temp);
  return 0;
}