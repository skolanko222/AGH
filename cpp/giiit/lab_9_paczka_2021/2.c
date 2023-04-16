#include <stdio.h>

struct dziennik
{
    int numer;
    struct pedagog
    {
        char *nazwisko;
    }nauczyciel;
    struct student
    {
        char * imie[1];
        char * nazwisko;
    }uczen[2];
    
    
}klasa;


int main(void)
{
    klasa.numer = 3;
    char *n = "Abacki";
    char *n2 = "Maly";
    char *i = "Jan";
    klasa.nauczyciel.nazwisko = n;
    klasa.uczen->nazwisko = n2;
    klasa.uczen[2].imie[1] = "Jan";

    printf("%d, %s, %s, %s\n",klasa.numer,klasa.nauczyciel.nazwisko, klasa.uczen->nazwisko,klasa.uczen[2].imie[1]);

    

    return 0;
}