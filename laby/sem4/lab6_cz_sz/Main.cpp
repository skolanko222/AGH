/*
  Celem zadania jest rozszerzenie jego wersji podstawowej, kopiowalnej polaczonej listy:
  https://upel.agh.edu.pl/mod/assign/view.php?id=121886
  Rozszerzenie obejmuje:
  - dodatkowy typ Boolean
  - funkcjonalność List::clone_if_exists (patrz niżej)
  - funkcjonalność List::numeric (patrz niżej)
  - funkcjonalność List::non_numeric (patrz niżej)
 */
#include <iostream>
#include "List.h"
#include "Data.h"

int main() {
  List a;
  a.insert(IntData(10), List::Begin);
  a.insert(Boolean(true), List::End);     // Nowy typ danych: Boolean
  a.insert(StringData("Hello"),  List::Begin);
  a.insert(IntData(7)).insert(Boolean(false));
  
  a.print();

  List b = a;
  b.insert(IntData(99));
  std::cout << "Lista a" << std::endl;
  a.print();
  std::cout << "Lista b" << std::endl;
  b.print();
  
  if(const LData* found_IntData = a.clone_if_exists( IntData(7) )){   // Zwracamy wskaźnik na klona, jeśli istnieje na liście,
    std::cout << "found_IntData: " << *found_IntData << std::endl;    // w innym przypadku nullptr
    delete found_IntData;
  }
  if(const LData* found_StringData = a.clone_if_exists( StringData("Hello") )){
    std::cout << "found_StringData: " << *found_StringData << std::endl;
    delete found_StringData;
  }
  if( a.clone_if_exists( StringData("HelloAgain") ) == nullptr)
    std::cout << "not found_StringData"<< std::endl;
  
  List c = a.numeric();       // Zwracamy kopię elementów listy a które są wartościami numerycznymi
  List d = a.non_numeric();   // Zwracamy kopię elementów listy a które NIE są wartościami numerycznymi
                              // Proszę zwrócić uwagę na copy_ellision!
  c.print();
  d.print();

}
/* wynik
["Hello", 10, true, 7, false] 
Lista a
["Hello", 10, true, 7, false] 
Lista b
["Hello", 10, true, 7, false, 99] 
found_IntData: 7
found_StringData: "Hello"
not found_StringData
[10, 7] 
["Hello", true, false]
*/
