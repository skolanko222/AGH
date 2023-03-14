#include <stdio.h>
#include <string.h>

int number_cmp(char *num_1, char *num_2);

int main(int argc, char *argv[])
{
    printf("pierwsza liczba = %s \n", argv[1]);
    printf("druga liczba = %s \n", argv[2]);

    short wynik = number_cmp(argv[1],argv[2]);

    if(wynik == 1)
        printf("pierwsza wieksza od drugiej");
    else if(wynik == 0)
        printf("rowne");
    else if(wynik == -1)
        printf("pierwsza mniejsza od drugiej");
    else
        printf("BLAD");
    
    return 0;
}

int number_cmp(char *num_1, char *num_2)
{
    int wynik = strcmp(num_1, num_2);
    printf("%d ", wynik);


    return 11;
}