// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
// Celem zadania jest napisanie kilku klas związanych relacją
// dziedziczenia.  Klasy te opisuja elementarne ksztalty. Kazdy kształt
// posiada jakies polimorficzne metody i konieczna infrastrukture.
// 
// Dodatkowe wskazówki i założenia wykonania zadania znajdują się w definicji funkcji main.
// UWAGA: Przed rozpoczeciem pisania prosze przeczytac zadanie do konca.
// UWAGA: W tym zadaniu: PI to 3.1415. Wzor na pole trojkata: sqrt( x(x-a)(x-b)(x-c) ) 
// gdzie "x" to polowa obwodu trojkata.
//
// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i Main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab04/
// * archiwum nie powinno zawierać katalogu build/


#include <iostream>
#include "Kwadrat.h"
#include "Kolo.h"
#include "Trojkat.h"

int main() {
  Kwadrat k(4);
  Trojkat t(3,2,4);
  const Kolo ko(3);

  wypisz(k); // ma wypisac: Kwadrat o boku: 4
  wypisz(t); // ma sypisac: Trojkat o bokach: 3 2 4
  wypisz(ko);// ma wypisac: Kolo o promieniu: 3

  Ksztalt* b = new Kwadrat(7);
  wypisz(*b);
  delete b;
  
  b = new Kolo(7);
  wypisz(*b);
  delete b;
  
  const Ksztalt* wszystkie[] = {&k, &k, &ko, &t, &ko}; // obiekty powtorzone celowo
  for (const auto& ksztalt : wszystkie ) {
    ksztalt->wypisz(std::cout); 
    std::cout << ksztalt->polePow() << std::endl;
  }
}
/* wynik
Kwadrat o boku:4
Trojkat bokach:3 2 4
Kolo o promieniu:3
Kwadrat o boku:7
Kolo o promieniu:7
Kwadrat o boku:4
16
Kwadrat o boku:4
16
Kolo o promieniu:3
9.4245
Trojkat bokach:3 2 4
2.90474
Kolo o promieniu:3
9.4245
 */
