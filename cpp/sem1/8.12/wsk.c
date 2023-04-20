
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


void krok_val(float);
void krok_ref(float*);


int main(int argc, char **argv){

	printf("------------------------------------------- \n");
	printf(" wskaznik vs wartosc \n");
	printf("------------------------------------------- \n");  

    float n=2.4;
	float * pn; // wskaznik bez wartosci ( nie ma tam jeszcze zadego adresu)
	pn= &n ; // pn ma teraz adres zmienne &n
	printf("zmianna n ma wartosc %f\n", n);
	printf("zmianna n ma adres %p\n", &n);
	//printf("zmianna n ma adres %p\n", n); // zle bo n jest liczba nie wskaznikiem
	//printf("zmianna n ma wartosc  %f\n", &n); // zle bo musze podac wartosc a nie adres
	//printf("zmianna n ma wartosc  %x\n", &n); // zle ale wypisze wartosc adresu, choć nie całego
	printf("zmianna pn ma wartosc %p\n", pn); // ok, wypisuje adres zmienne n
    printf("zmianna pn ma adres %p\n", &pn); // ok, ale czy napewno o to chodziło? wypisze adres wskaznika 
	printf("zmianna n ma wartosc %f\n", *pn); // ok,  dobieram sie do zmiennen przez adres który jest we wskazniku, * oznacza tu "wartosc na ktora wskazuje wskaznik"
	//printf("zmianna n ma wartosc %f\n", *n); // zle, nawet sie nie skompiluje bo n nie wskazuje na nic(bo nie jest wskznikiem) wiec nie mozna uzyc *n
	printf(" \n");


	printf("------------------------------------------- \n");
	printf(" Podawanie wartosci i wskzników do funkcji \n");
	printf("------------------------------------------- \n");    

	krok_val(n);  // OK, podanie wartosci jako argument
    printf("n po krok_val %f \n",n);
	printf("------------ \n");

	//krok_val(pn);  // zle, musi podac wartosc a nie adres

	//krok_val(&n);  // zle, musi podac wartosc a nie adres

	krok_val(*pn);  // ok podalem wartosc
    printf("n po krok_val %f \n",n);
	printf("------------ \n");

	printf(" \n");
    printf("------------------------------------------- \n");
	printf(" \n");

    krok_ref(&n);  // OK, podanie adres jako argument
    printf("po krok_raf %f \n",n);	
	printf("------------ \n");

    krok_ref(pn);  // OK, podanie adres jako argument
    printf("po krok_raf %f \n",n);	
	printf("------------ \n");

    //krok_ref(n);  // zle, mial byc adres  nie wartosc
	//krok_ref(*pn);  // zle, mial byc adres  nie wartosc
	//krok_ref(&pn);  // Ok ale czy o to chodziło? 
	//printf("zmianna pn ma wartosc %p\n", pn); // 
	//printf("zmianna wskazuje na wartosc  %f\n", *pn); // 


	return 0;
}

void krok_val(float n){
	// n jest tutaj lokalna kopia zmienne i nie ma nic wspolnego z n poza ta funkcja, przypadkowo nazwalismy ja tak samo litera n
	n=n+1.0;
	printf("wartosc n wewnatrz= %f \n",n);
	printf("adres zmiennej n wewnatrz krok_val = %p \n",&n); //inny niz adres zmiennej n z funkcji main bo to inna zmienna n

}

void krok_ref(float *n){   // wskazniek nazywa sie *n ale moze nazywac sie dowolnie, to jest tylko lokalna nazwa weawnatrz tej funkcji

	printf("otrzymalem adres %p\n", n);
	
	*n = *n+1.f;  //*n oznacza wartosc na ktora wskazuje pointer(wskaznik) n
	printf("wartosc na ktora wskazuje przekazany adres= %f \n",*n);
	
}

