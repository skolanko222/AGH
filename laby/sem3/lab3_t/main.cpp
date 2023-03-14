// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac funkcje wykonujace operacje na tablicach
// reprezentujacych liste studentow.

// W tablicy "namesList" przechowywane są imiona
// W tablicy "yearsList" przechowywane sa lata na ktorych studiują studenci.

// UWAGA:
// Tablice powinny dostosowywac sie do liczby elementow, ktore maja byc w
// nich przechowywane. Zarządzanie pamięcią należy implementować z wykorzystaniem
// operatorów new / delete, new[] / delete[].

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab03/
// * archiwum nie powinno zawierać katalogu build/
// * tworzenie archiwum: tar -czvf nazwa.tar.gz zad/

#include "lab.h"

int main ()
{
  int numberOfStudents = 0;
  char** namesList = NULL;
  int* yearsList = NULL;

  AddStudent(&numberOfStudents, &namesList, &yearsList, "Spike", 3);
  AddStudent(&numberOfStudents, &namesList, &yearsList, "Rick", 5);
  AddStudent(&numberOfStudents, &namesList, &yearsList, "Sterling", 1);

  Cat(numberOfStudents, namesList);
  Cat(numberOfStudents, yearsList);

  ClearList (numberOfStudents, &namesList);
  ClearList (numberOfStudents, &yearsList);
  numberOfStudents = 0;
  return 0;
}
/* wynik dzialania programu:
build$ ./StudListFilters
Spike
Rick
Sterling
3
5
1
*/
