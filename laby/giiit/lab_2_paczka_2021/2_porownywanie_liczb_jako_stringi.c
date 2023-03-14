#include <stdio.h>
#include <string.h>

int number_cmp(char *num_1, char *num_2);

int main(int argc, char *argv[])
{
    printf("pierwsza liczba = %s \n", argv[1]);
    printf("druga liczba    = %s \n", argv[2]);

    short wynik = number_cmp(argv[1],argv[2]);

    if(wynik > 0)
        printf("pierwsza wieksza od drugiej");
    else if(wynik == 0)
        printf("rowne");
    else if(wynik < 0)
        printf("pierwsza mniejsza od drugiej");
    else
        printf("BLAD"); 
    
    return 0;
}

int number_cmp(char *num_1, char *num_2)
{ 

    int len_1 = strlen(num_1);
    int len_2 = strlen(num_2);
    if(len_1 > len_2)
        return 1;
    else if(len_1 < len_2)
        return -1;
    else
        return strcmp(num_1, num_2);

    
}