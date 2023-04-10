/*
  Celem zadania jest napisanie polimorficznej kopiowalnej polaczonej listy:
  - list data structure: 
    https://www.geeksforgeeks.org/insertion-in-linked-list/;
  - polimorficzność listy jest uzyskana poprzez przechowywanie referencji do danych poprzez 
    wskaźnik typu klasy bazowej dla klas poszczególnych typów: IntData, StringData;
  - klasa bazowa jest klasą abstrakcyjną, tutaj definiującą interfejs do klonowania i wydruku wartości
    danych na wyjście std::ostream;
  - List::Begin/End jest składnikiem wyliczeniowym (enum) klasy List
  UWAGA: Zadanie posiada kilka haczykow. W szczegolnosci konstruktor kopiujacy.
*/

#include <iostream>
#include "List.h"
#include "Data.h"

int main() {
  List a;
  a.insert(IntData(10), List::Begin);   // wkladamy na poczatek
  a.insert(IntData(11), List::End);     // na koniec
  a.insert(StringData("Hello"),  List::Begin); // znow na poczatek
  a.insert(StringData("Kasia"), List::End);
  a.insert(IntData(7)).insert(StringData("WhereAmI")); // po wyniku mozna poznac gdzie domyślnie dodawane są elementy
  
  a.print();

  List b = a;
  b.insert(IntData(99));
  std::cout << "Lista a" << std::endl;
  a.print();
  std::cout << "Lista b" << std::endl;
  b.print();
}
/* wynik: 
~IntData()
~IntData()
~StringData()
~StringData()
~StringData()
~IntData()
["Hello", 10, 11, "Kasia", 7, "WhereAmI"] 
~IntData()
Lista a
["Hello", 10, 11, "Kasia", 7, "WhereAmI"] 
Lista b
["Hello", 10, 11, "Kasia", 7, "WhereAmI", 99] 
~IntData()
~StringData()
~IntData()
~StringData()
~IntData()
~IntData()
~StringData()
~StringData()
~IntData()
~StringData()
~IntData()
~IntData()
~StringData()
 */
