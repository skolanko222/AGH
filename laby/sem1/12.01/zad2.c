
/*Skopiuj podany niżej program i zapisz do pliku. Dokończ funkcję hex() tak, aby zamieniała wartość zmiennej p na trzycyfrową cyfrową liczbę szesnastkową (bez znaku), zapisaną w tablicy znakowej tab. Tablica zawiera 4 elementy: tab[0] to najstarsza cyfra, tab[2] to najmłodsza, natomiast do dodatkowego elementu tab[3] należy przypisać znak pusty '\0', oznaczający koniec łańcucha. Funkcja powinna wypisywać obliczoną liczbę szesnastkową przy pomocy specyfikatora %s (to jest już zrealizowane w kodzie poniżej) lub informować o błędzie, jeśli wartości p nie da się zamienić na trzycyfrową liczbę szesnastkową.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3

void hex(int p){
	char tab[N+1];
    tab[3] = '\0';
    
   
	//TU EDYTOWAC
    int tab_i[N];
    int q=p;
    for(int i=2; i>=0;i--){
        tab_i[i]=q%16;
        q/=16;
        
        if (tab_i[i]>=0 && tab_i[i]<=9)
          tab[i] = (char)tab_i[i];
        else tab[i] = (tab_i[i]-10)+17;
       
    }
        printf("%4d = %s\n",p,tab);
}

int main(void){
	for(int i=1; i<=4097; i++)
		if(i<3 || (i>8 && i<17) || i>4093 || i%1000==0)
			hex(i);
	return 0;
}
