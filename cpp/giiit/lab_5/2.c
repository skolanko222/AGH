#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * zamien_slowo(char text[], char usun[], char zamien[])
{
    char *wynik = malloc(strlen(text)*sizeof(char));  
    strcpy(wynik, text);

    int size = strlen(wynik);

    while(strstr(wynik,usun) != NULL)
    {

        wynik = realloc(wynik, ((size+strlen(zamien)+1))*sizeof(char));
        size += strlen(zamien) + 1;
        memmove(strstr(wynik, usun) + strlen(zamien), strstr(wynik, usun) + strlen(usun), strlen(strstr(wynik, usun)) - strlen(usun));
        memmove(strstr(wynik,usun), zamien, strlen(zamien));
        
    }
    
    printf("%d", size);
    //wynik[64] = '\0';
    //printf("%s",wynik);
    return wynik;
}

int main(void)
{
    char TEXT_1[] = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
    char TEXT_2[] = "sie";
    char TEXT_3[] = "Alicja";

    char *TEXT_4 = zamien_slowo(TEXT_1,TEXT_2,TEXT_3);

    puts(TEXT_4);

    return 0;
}