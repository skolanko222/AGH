/*
  Celem zadania jest rozszerzenie jego wersji podstawowej kopiowalnej polaczonej listy:
  https://upel.agh.edu.pl/mod/assign/view.php?id=121886
  oraz własnej implementacji z lab06
  Rozszerzenie obejmuje:
  - dodatkowe typy (jeśli potrzeba)
  - funkcja List::numeric która zwraca nową listę, jedynie z wartościami numerycznymi
  - szablonowa funkcja swap
  - funkcja List::convert_to_stringdata która zwraca nową listę, w której wszystkie dane 
    przekonwertowane zostały na typ StringData
 */
#include <iostream>
#include "Algorithm.h" // definicja funkcji swap
#include "List.h"
#include "Data.h"

int main() {
  List a,b;
  a.insert(IntData(1)).insert(IntData(2)).insert(IntData(3));
  a.insert(Boolean(true)).insert(Boolean(false));
  b.insert(FloatData(4.1)).insert(FloatData(5.2)).insert(FloatData(6.3));
  b.insert(StringData("Dummy")).insert(StringData("Data"));
  a.print();
  b.print();
  swap<List>(a,b);
  a.print();
  b.print();
  List c = b.numeric();
  c.print();
  c.convert_to_stringdata().print();
}
/* wynik
[1, 2, 3, true, false] 
[4.1, 5.2, 6.3, "Dummy", "Data"] 
[4.1, 5.2, 6.3, "Dummy", "Data"] 
[1, 2, 3, true, false] 
[1, 2, 3] 
["1", "2", "3"] 
*/