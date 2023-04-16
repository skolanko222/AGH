#include "Filters.h"
#include <iostream>

void cat(char ** napis)
{
    char ** temp = napis;
    while(*temp != nullptr){
        std::cout << *temp << std::endl;
        temp++;
    }

    return ;
}

int wc_lines(char ** napis)
{
    char ** temp = napis;
    int licznik=0;
    while(*temp != nullptr){
        licznik++;
        temp++;
    }

    return licznik;
}

int wc_char(char ** napis)
{
    char ** temp = napis;
    int licznik=0;
    while(*temp != nullptr){
        char * temp2 = *temp;
        while(*temp2 != '\0')
        {
            licznik++;
            temp2++;
        }
        temp++;
    }

    return licznik;
}

int wc_char(char * napis)
{
    int licznik=0;
    char * temp2 = napis;
        while(*temp2 != '\0')
        {
            licznik++;
            temp2++;
        }

    return licznik;
}

int wc_words(char ** napis)
{
    char ** temp = napis;
    int licznik = 0;
    while(*temp != nullptr){
        licznik++;
        char * temp2 = *temp;
        while(*temp2 != '\0')
        {
            if(*temp2 == '_')
                licznik++;
            temp2++;
        }

        temp++;
    }

    return licznik;
}

void clear(char ** napis)
{

    return;
}

char ** tail(int ile, char ** napis)
{
    char ** temp = napis;
    int licznik = 0;
    while(*temp != nullptr) 
    {
        temp++;
        licznik++;
    }
    if(ile >= licznik)
        return napis;
    return temp - ile;

}

char ** head(int ile, char ** napis)
{

    return nullptr;
}

char ** uniq(char ** napis)
{


    return nullptr;
}
