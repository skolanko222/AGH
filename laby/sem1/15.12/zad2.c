#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*generator losowego hasła z liter(male i duze) , cyfr oraz znaki specjalne (np !#$%^ itp) , jako argument funkcji mian długość hasła. Program jako output wypisuje haslo. */

int i_rand(int min, int max){
	return rand() % (max-min+1) + min;
}


int main(int argc, char* argv[])
{
    srand(time(0));

    int dlugosc = atoi(argv[1]);
    
    char haslo[dlugosc];
    
        for(int i=0;i<dlugosc;i++){ //losowanie hasla

            haslo[i] = (char)i_rand(48,126);
           
            
        }
        for(int i=0;i<dlugosc;i++){ //wypisanie hasla
        
         printf("%c",haslo[i]);
        
        
        }


    return 0;
}
