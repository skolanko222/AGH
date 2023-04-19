#include <stdio.h>                     //konieczne biblioteki
#include <string.h>                 

int main(int argc, char *argv[])
{     int nap_1[argc-1], nap_2[argc-1]; //deklaracja koniecznych zmiennych, miedzy innymi tablic nap_1 oraz nap_2 
  
     
    for(int i = 1; i < argc; i++)
    {
    
        nap_1[i] = argv[i];
        nap_2[i] = argv[i];

    } //zapisanie argumentów wywołania programu do tablic nap_1 oraz nap_2

printf ("A -->  napis_1 = %s napis_2 = %s\n", nap_1[0], nap_2[1]);   //zostanie wypisane: A --> napis_1 = Jedenascie napis_2 = Dwiescie 
  
                                //wymiana zawartosci tablic nap_1 i nap_2

printf ("B -->  napis_1 = %s napis_2 =  %s\n", nap_1[1], nap_2[0]);    //zostanie wypisane: B --> napis_1 = Dwiescie napis_2 = Jedenascie 
return 0;
}  
