/*
  Celem zadania jest rozszerzenie jego wersji podstawowej, kopiowalnej polaczonej listy:
  https://upel.agh.edu.pl/mod/assign/view.php?id=121886
  Rozszerzenie obejmuje:
  - dodatkowy typ FloatData
  - funkcjonalność List::find która weryfikuję czy na liście znajduje się element przekazany przez parametr
  - przeciążenie operatora << dla klasy List, z funkcjonalnością konkatencji list

  UWAGA:
  - praktycznym w zadaniu mogą się okazać pomocnicze metody/interfejs w klasie bazowej
    do różnych typów danych (w różnych w kontekstach zadania):
    virtual bool isSame( const LData& ) const = 0;
    virtual void printTo(std::ostream& str) const = 0;

  - std::dynamic_cast na referencji w przypadku niepowodzenia zwraca std::bad_cast,
    (dla wskaźników po prostu zwraca nullptr).
    Dlatego, należy zastosować mechaniż przechwytywania wyjątku:
    try {
      ... dynamic_cast<...>(...)
      return ...
    } catch(std::bad_cast) {
      return false; // w kontekście zadania
    }

 */
#include <iostream>
#include "List.h"
#include "Data.h"

int main() {
  List a;
  a.insert(IntData(10), List::Begin);
  a.insert(FloatData(11), List::End);     // Nowy typ danych: FloatData
  a.insert(StringData("Hello"),  List::Begin);
  a.insert(IntData(7)).insert(FloatData(0.3));
  
  a.print();

  List b = a;
  b.insert(IntData(99));
  std::cout << "Lista a" << std::endl;
  a.print();
  std::cout << "Lista b" << std::endl;
  b.print();
  
  bool found = a.find( IntData(7) );  // Zwracamy prawdę lub fałsz w zależności wyniku wyszukiwania
  std::cout << "found in a: " << std::boolalpha << found << std::endl;
  found = a.find( StringData("Kasia") );
  std::cout << "found in a: " << found << std::noboolalpha << std::endl;

  a << b << b;  // Konkatenacja list. Z listy b dane zostają pzreniesione do listy a, bez kopiowania!
                 // Powtórzenie jest celowe.
  a.print();
  b.print();


}
/* wynik
["Hello", 10, 11, 7, 0.3] 
Lista a
["Hello", 10, 11, 7, 0.3] 
Lista b
["Hello", 10, 11, 7, 0.3, 99] 
found in a: 1
found in a: 0
["Hello", 10, 11, 7, 0.3, "Hello", 10, 11, 7, 0.3, 99] 
[]
*/
