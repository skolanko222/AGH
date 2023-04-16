#include <stdio.h>
#include <stdlib.h>

/*Napisz funkcję zgodną z prototypem:
unsigned int count1(unsigned int p);
Funkcja powinna zwracać liczbę jedynek znajdujących się w reprezentacji binarnej podanej liczby całkowitej bez znaku unsigned int p przy użyciu operatora przesunięcia bitowego w lewo. W main() przetestuj działanie zapisanej funkcji, przekazując do niej liczbę 250. W efekcie program powinien wypisać:

Liczba 250 ma 6 jedynek.*/

unsigned int count1(unsigned int p);

int main()
{

    int a = 250;
    
    printf("Ilosc jedynek w binarnej reprezentacji liczby %d jest rowna: %d \n",a,count1(a));

    return 0;
}

unsigned int count1(unsigned int p){
    
    int dlugosc=0, ilosc=0;
    while(p){
        
        p>>=1;
        ilosc += p & 1;
        dlugosc++;
    }
   
    
    return ilosc;
    
    
}
