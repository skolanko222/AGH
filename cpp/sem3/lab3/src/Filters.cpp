#include <iostream>

void cat(char ** napis)
{
    if(*napis == nullptr)
    {
        std::cout << "Nic do przeczytania!" << std::endl;
        return;
    }
    char **temp = napis;
    while(*temp != nullptr)
    {
        std::cout << *temp << std::endl;
        temp++;
    }
    return;
}

int wc_lines(char ** napis)
{
    if(*napis == nullptr)
    {
        std::cout << "Nic do przeczytania!" << std::endl;
        return;
    }
    char **temp = napis;
    int licznik = 0;
    while(*temp != nullptr)
    {
        licznik++;
        temp++;
    }

    return licznik;
}

int wc_char(char ** napis)
{
    if(*napis == nullptr)
    {
        std::cout << "Nic do przeczytania!" << std::endl;
        return;
    }
    char **temp = napis;
    int licznik = 0;
    while(*temp != nullptr)
    {
        char *temp2 = *temp;
        while(*temp2 != '\0')
        {
            temp2++;
            licznik++;
        }
        temp++;
    }

    return licznik;
}

int wc_char(char * napis)
{
    if(*napis == nullptr)
    {
        std::cout << "Nic do przeczytania!" << std::endl;
        return;
    }
    char *temp = napis;
    int licznik = 0;
    while(*temp != '\0')
    {
        temp++;
        licznik++;
    }
    temp++;


    return licznik;
}

int wc_words(char ** napis)
{
    char **temp = napis;
    int licznik = 0;
    while(*temp != nullptr)
    {
        char *temp2 = *temp;
        while(*temp2 != '\0')
        {
            if(*temp2 == '_' && *(temp2 + 1) != '\0')
                licznik++;
            
            temp2++;
        }
        licznik++;
        temp++;
    }

    return licznik;
}

void clear(char ** buf)
{
    delete [] buf;

    return;
}

char ** tail(int ile, char ** napis)
{
    char ** temp = napis;
    int licznik = wc_lines(napis);
    while(*temp != nullptr) 
        temp++;

    if(ile > licznik)
        return napis;

    return temp - ile;
}

char ** head(int ile, char ** napis)
{
    char ** temp = napis;
    int licznik = wc_lines(napis);
    
    if(ile > licznik)
        ile = licznik;

    char ** head_napis = new char *[ile + 1];

    for(int i = 0; i < ile; i++)
    {
        
        head_napis[i] = napis[i];

    }

    head_napis[ile] = nullptr;

    return head_napis;
}
bool str_cmp(char * napis1, char * napis2)
{

    while(*napis1 != '\0' && *napis2 != '\0')
    {
        if(*napis1 != *napis2)
            return 0;
        napis1++;
        napis2++;
    }
    if(*napis1 == *napis2)
        return 1;

    return 0;
}

//niedokonczone
char ** uniq(char ** napis)
{
    
    char ** temp = napis;
    char ** temp2;
    
    //while(*temp != nullptr)
    {
        temp2 = napis;
        //while(str_cmp(*temp2, *temp))
        {

        }
        //temp++;
    }


    return nullptr;
}