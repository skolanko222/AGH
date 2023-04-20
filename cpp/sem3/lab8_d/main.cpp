/*
Celem zadania jest powtórzenie różnego rodzaju konwersji, przećwiczenie definicji własnych przestrzeni nazw oraz budowania projektu w trybie debug i release.
Zadanie jest częściowo kontynuacją zadania z poprzednich zajęć, więc warto skorzystać z kodu klasy Wymierne.
Prosze jednak wprowadzić istotne zmiany:
 * proszę zwrócić uwagę, że do klasy Wymierne należy dołożyć skracanie ułamka:
 do wykorzystania w funkcji simplify
  int nwd(int m, int n){
  int oldm, oldn;
    while( m % n != 0 ){
        oldm = m;
        oldn = n;
      m = oldn;
      n = oldm % oldn;
  }
    return n;
  } 

Ponadto definiujemy nowy niezbędny kod w pliku Double.h (jest krótki, więc bez rozdzielania na cpp). Każde wyświetlenie obiektu jest zliczane. Licznik jest prywatną składową klasy.
UWAGA:
Wartość składowa Double nie może być mutable, korzystamy z const-cast.
Wszystkie operatory konwersji w klasie Wymierne mają wymagać jawnego rzutowania.(za brak -1 pkt)

Zadanie do domu: 
Podzielić projekt na dwa foldery debug(dbg) i release(rls) i tak skonfigurować CMakeLists.txt, aby kompilował obie wersje w zależności od użytych flag.
*/

#include <iostream>
#include <cmath>

#include "Wymierne.h"
#include "Double.h"


// #define ERROR

int main() {
//////////////////////////////////////////////////////////
#ifdef DEBUG //cmake -DCMAKE_BUILD_TYPE=Debug ..
    std::cout << "Uruchamiam Debug build.\n";
    using namespace dbg;
#else  //cmake -DCMAKE_BUILD_TYPE=Release .. albo cmake ..
    std::cout << "Uruchamiam Release build.\n";
    using namespace rls;
#endif
  
  std::cout << "\n*** WYMIERNE ***"<< std::endl;
  Wymierne Raz(2, 4);
  const Wymierne Dwa(3, 4), Trzy, Cztery(2,0);
  Raz.print("Raz = ");
  Dwa.print("Dwa = ");
  Trzy.print("Trzy = ");
  Cztery.print("Cztery = ");

  Wymierne W1 = pomnoz(Raz, Dwa);
  W1.print("W1 = ");
  double L1 = static_cast<double>(W1);
  std::cout<< L1 << std::endl;

  Wymierne W2 = Wymierne::pomnoz(Dwa, static_cast<Wymierne>(6));
  W2.print("W2 = ");
  
#if DEBUG
  std::cout << "Wersja Debug\n";
  const Wymierne W3 = dbg::pomnoz(Wymierne(2), Wymierne(5,2));
#else
  std::cout << "Wersja Release\n";
  Wymierne W3 = rls::pomnoz(Wymierne(2), Wymierne(5,2));
#endif
  
  W3.print("W3 = ");
  W3.setM(12);
  W3.print("W3 = ");
  double L2 = pow(static_cast<double>(W2),-2);
  std::cout<< L2 << std::endl;

  ////////////////////////////////////////////////////
  std::cout << "\n*****  DOUBLE  *****"<< std::endl;
  std::cout << "----- Obiekt x -----\n";
  const Double x {3.};
  print(x);
#ifdef DEBUG
  x.setconstx(pow2(x));
  // x.setx(pow2(x)); //ma zwrócić błąd
  print(x);
  x.setconstx(pow2(x));
  x.print();
#endif
  std::cout << "----- Obiekt y -----\n";
  Double y(Dwa);
  y.print();
  y.setx(x);
  print(y);
  y.setx(static_cast<double>(Wymierne(4,5)));
  print(y);
  
  std::cout << std::endl;
////////////////////////////////////////////////////// 
	
#ifdef ERROR
  wymierne::sum(1.5, 2.5).print();  
#endif

}
/* oczekiwany wynik
Uruchamiam Release/Debug build

*** WYMIERNE ***
Raz = 1/2
Dwa = 3/4
Trzy = 0
Cztery = 2
W1 = 3/8
0.375
W2 = 9/2
Wersja Release/Debug
W3 = 5
W3 = 5/12
0.0493827

*****  DOUBLE  *****
----- Obiekt x -----
Print nr 1. Val = 3
Print nr 2. Val = 9  // Debug
Print nr 3. Val = 81 // Debug
----- Obiekt y -----
Print nr 1. Val = 0,75
Print nr 2. Val = 81
Print nr 3. Val = 0.8
*/
