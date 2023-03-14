#include <stdio.h>
#include <stdlib.h>
#include "pi.c"

/*Zlicz ile jest częstość wystąpień różnych cyfr w liczbie pi? Program ma wypisać częstość wystąpień każdej z 10ciu cyfr

Zadania zrób za pomocą funkcji która pobiera string i liczbę i zwraca wynik za pomocą return


ile jest różnych podciągów dwuznakowych np "12" oraz "33" w liczbie pi?

Zadania zrób za pomocą funkcji która pobiera string z liczbą pi oraz drugi string z dwoma cyframi i zwraca wynik (int )za pomocą return

Tablice z liczba pi (200k liczb) zaimportuj używając

#include "pi.c"  */

int ilosc(char[],int);
int perm(char[],int);


int main()
{
    int dl=sizeof(pi)/sizeof(pi[0]);
    ilosc(pi,dl);
    


    return 0;
}

int ilosc(char[],int);

int ilosc(char pi[],int dl){
    
    int ilosc[10];
    
    for(int i=0;i<=dl;i++){
        if(pi[i]=='0') ilosc[0]+=1;
        if(pi[i]=='1') ilosc[1]+=1;
        if(pi[i]=='2') ilosc[2]+=1;
        if(pi[i]=='3') ilosc[3]+=1;
        if(pi[i]=='4') ilosc[4]+=1;
        if(pi[i]=='5') ilosc[5]+=1;
        if(pi[i]=='6') ilosc[6]+=1;
        if(pi[i]=='7') ilosc[7]+=1;
        if(pi[i]=='8') ilosc[8]+=1;
        if(pi[i]=='9') ilosc[9]+=1;


    }
    
    for(int i=0;i<11;i++){
        return ilosc[i];
    
    }
    


   
}
