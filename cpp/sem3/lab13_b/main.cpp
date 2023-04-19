/*
 Celem zadania jest napisanie kilku klas powiązanych relacją dziedziczenia. Klasy te opisują elementarne operacje matematyczne. 
 Każda z nich ma jakieś polimorficzne metody i konieczną infrastrukturę.
 
 Proszę dopisać potrzebne klasy o oodpowiedniej hierarchii
 oraz funkcje tak, aby program kompilował się i dawał oczekiwany wynik.
 Wykorzystanie dziedziczenia w tym zadaniu ma na celu uniknięcie kopiuj-wklej, przechowywania i wykonywania jak najwięcej wspólnych czesci w klasie bazowej (Operation), a nie tworzenia klasy wirtualnej.
 
 W klasie VSum nie trzeba się przejmować, czy rozmiar tablicy jest prawidłowy. 
 Klasy pochodne oraz OpComp proszę w całości zdefiniować w pliku nagłówkowym, jedynie Operation proszę rozdzielić na h i cpp.

 Dodatkowo klasa OpComp jest funktorem porównującym ze sobą obiekty MathObj, czy wykonują te same działania.
 */

#include "Operation.h"
#include "Div.h"
#include "Power.h"
#include "VSum.h"
#include "OpComp.h"

#include <iostream>

#define BASIC

int main() {
  Div div(4,2);
  Power pow(5, -2);
  const int n = 4;
  double numbers[n] = {1,3.2,5,11};
  const VSum sum(numbers, n);

  std::cout << div.name() << " (" << div.op() << "): ";
  div.print(std::cout); 
  std::cout << " = " << div.eval() << std::endl;  
  std::cout << pow.name() << " (" << pow.op() << "): ";
  pow.print(); // ta sama funcja co powyzej, argument domyślny
  std::cout << " = " << pow.eval() << std::endl;
  std::cout << sum.name() << " (" << sum.op() << "): ";
  sum.print();
  std::cout << " = " << sum.eval() << std::endl;

  Operation* d1(new Div(7,2));
  std::cout << *d1;

  Operation* d2(new VSum(numbers, n));
  (*d2)[2] = 7.5;
  std::cout << *d2;

  std::cout << "=====================================" << std::endl;

  const Operation* all[] = {&div, &pow, &sum}; 
  for ( unsigned i = 0; i < sizeof(all)/sizeof(Operation*); ++i ) {
    std::cout << *all[i];
  }  
#ifndef BASIC
  std::cout << "=====================================" << std::endl;
  OpComp isDiv(d1);
	OpComp isSum(d2);
	std::cout << std::boolalpha;
	std::cout << (d1->op() == div.op()) << "\t --- " << isDiv(&div) << std::endl;
	std::cout << (d1->op() == d2->op()) << "\t --- " << isDiv(d2) << std::endl;
	std::cout << (d2->op() == sum.op()) << "\t --- " << isSum(&sum) << std::endl;
	std::cout << (d2->op() == d1->op()) << "\t --- " << isSum(d1) << std::endl << std::endl;
#endif
  
  delete d1;
  delete d2;

}

/* oczekiwany wynik

Dzielenie (/): 4 / 2  = 2
Potega (^): 5 ^ -2  = 0.04
Dodawanie (+): 1 + 3.2 + 5 + 11  = 20.2
7 / 2  = 3.5
1 + 3.2 + 7.5 + 11  = 22.7
=====================================
4 / 2  = 2
5 ^ -2  = 0.04
1 + 3.2 + 5 + 11  = 20.2
=====================================
true     --- true
false    --- false
true     --- true
false    --- false

 */
