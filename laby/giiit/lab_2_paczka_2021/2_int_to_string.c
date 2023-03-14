#include <stdio.h>
// n - to liczba bitów
unsigned bits(unsigned x, unsigned n);  
void write_binar(unsigned n, char *wsk); // nalezy wykorzystac maske bitowa
int binary_size(int i);

int main()
{
    unsigned result, number, bit_num;

    printf("Podaj liczbe: ");

    scanf(" %d", &number);

    printf("Podaj liczbe bitow: ");

    scanf(" %d", &bit_num);
    
    int size = binary_size(number); //żeby wiedzieć ile miejsca zarezerwowac

    char number_string[size]; // tablica na zapis binarny
    write_binar(number, number_string+size);
    
    
    printf("liczba wczytana %d : %s\n", number, number_string);        // liczba wczytana 435 : 00000000000000000000000110110011 

    result = bits(number, bit_num); 

    char result_binary[binary_size(result)];
    write_binar(result, result_binary+binary_size(result));

    printf("%u najmlodszych bitow %s \n", bit_num, result_binary); // 7 najmlodszych bitow: 00000000000000000000000000110011 
    return 0;
}
void write_binar(unsigned n, char *wsk)
{
    int i=1;
    *wsk = '\0';
    do 
    {
        if(n&1)
            *(wsk-i) = '1';
        else    
            *(wsk-i) = '0';
        n>>=1;
        i++;
    }while(n); 
   
}

unsigned bits(unsigned x, unsigned n)
{
    int maska = 1;

    for(int i = 0; i < n; i++)
    {
        maska <<= 1;
    }

    return x & (maska-1);

}
int binary_size(int i)
{
    int size=0;
    while(i)
    {
        i=i>>1;
        size++;
    }

    return size;

}