/* 
Zdefiniować klasę reprezentującą tablicę asocjacyjną gdzie typ klucza i typ wartosci są składowymi klasy (jako osobna klasa albo struktura).
NIE WOLNO korzystać z gotowych kontenerów, tablica ma się dynamicznie powiększać  po dodaniu nowego elementu.
Funkcje składowe należy odczytać z kodu. Należy zdefiniować operator przypisania i operatory dostępu do elementów. 
*/

#include <iostream>
#include <string>

#include "assoc.h"

using namespace std;

int main() {
  cout << "***** Tablica asocjacyjna z kluczem napisowym *****" << endl;
  Assoc m,m2;  // kolejność klucz, wartość
  m.insert("matematyka", 4.5 );
  m.insert("fizyka", 3.0 ); 
  m.print("--- Element tablicy");
  m["angielski"] = 3.5; // dodawanie wartości za pomocą klucza
  m["fizyka"] = 5.0;
  m["chemia"] = 2.;
  m.print("--- Po modyfikacji");
  /*m2=m=m;
  
  cout << "\n***** Tablica const *****" << endl;
  const Assoc& cm = m2;  
  cm.print("--- Kopia: ");
  cout << "Wartosc pod fizyka? " << cm["fizyka"] << endl;
  cout << "Czy jest matma? \t" << print(cm.contains("matma")) << endl;
  cout << "Czy jest angielski? \t" << print(cm.contains("angielski")) << endl;*/
}
  

/* oczekiwany wynik
***** Tablica asocjacyjna z kluczem napisowym *****
--- Element tablicy klucz: matematyka wartosc: 4.5
--- Element tablicy klucz: fizyka wartosc: 3
--- Po modyfikacji klucz: matematyka wartosc: 4.5
--- Po modyfikacji klucz: fizyka wartosc: 5
--- Po modyfikacji klucz: angielski wartosc: 3.5
--- Po modyfikacji klucz: chemia wartosc: 2

***** Tablica const *****
--- Kopia:  klucz: matematyka wartosc: 4.5
--- Kopia:  klucz: fizyka wartosc: 5
--- Kopia:  klucz: angielski wartosc: 3.5
--- Kopia:  klucz: chemia wartosc: 2
Wartosc pod fizyka? 5
Czy jest matma?         Nie znaleziono
Czy jest angielski?     Znaleziono
 */
