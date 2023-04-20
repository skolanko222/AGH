/*
Uzupełnij kod tak, aby program się kompilował.
Zadanie ma na celu zaimplementowanie przećwiczenie cout, new, delete i operacji na wskaźnikach na przykładzie prostych funkcji cat, head, tail, wc w różnych wariantach.
Nie można korzystać z cstring i ze zmiennej argc.
Separatorem słów w linii jest znak '_'
Z uwagi na to, że trudno byłoby przetestować cin, argumenty zadania są przekazywane w linii poleceń, kolejne testowe wywołania można uzyskać wywołując:
make run = ./main
make test1 = ./main Ala ma kota_Mruczka ma psa_Azora
make test2 = ./main ala_ma_kota ala_ma_kota
Oczekiwane rezultaty dla wszystkich trzech wariantów sa wypisane na końcu pliku.

WSKAZÓWKA:
Funkcja head wymaga alokacji pamięci, kopiujemy wskaźniki do zaalokowanej dynamicznie tablicy, której wskaźnik zwracamy. Rozmiar tablicy ma być dopasowany do liczby elementów.
Funkcja uniq wymaga alokacji pamięci, dla uproszczenia alokujemy tablicę takiej samej wielkości. Podobnie jak w head kopiujemy wskaźniki, nie trzeba wykonywać kopii napisów wskazywanych przez elementy tablicy. 

W tym zadaniu nie ma potrzeby dzielenia na pliki .h i .cpp wówczas nie trzeba tworzyć katalogu src
Pod koniec zajęć prześlij zadanie w postaci archiwum zip (spakuj include, src, main.cpp i CMakeLists.txt)
*/

#include <iostream>
#include "Filters.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
 //usunięcie z listy pierwszego argumentu i dodanie na koniec nullptr w celu wyeliminowanania argc
  for (int i=1;i<argc;i++)
    argv[i-1] = argv[i]; 
  argv[argc-1] = nullptr;
  
  cat(argv);
  cout << "Liczba linii: " << wc_lines(argv) << endl;
  cout << "Liczba znakow: " << wc_char(argv) << endl;
  cout << "Liczba znakow w 1 linii: " << wc_char(*argv) << endl;
  cout << "Liczba slow: " << wc_words(argv) << endl;
  
  cout << "---Tail 1: \n";
  cat(tail(1, argv));
  cout << "---Tail 10: \n";
  cat(tail(10, argv));
  
  cout << "---Head 1: \n";
  char** buf = head(1, argv);
  cat(buf);
  clear(buf);
  cout << "---Head 10: \n";
  buf = head(10, argv);
  cat(buf);
  clear(buf);
  
  cout << "---UNIQ:\n";
  char **struniq = uniq(argv);
  cat(struniq);
  cout << "---Tail 2: \n";
  cat(tail(2, argv));
  clear(struniq);

  return 0;  
}

/** Oczekiwany wynik
 *** dla make run = ./main ***
Liczba linii: 0
Liczba znakow: 0
Liczba znakow w 1 linii: 0
Liczba slow: 0
---Tail 1: 
---Tail 10: 
---Head 1: 
---Head 10: 
---UNIQ:
---Tail 2: 

*** dla make test1 = ./main Ala ma kota_Mruczka ma psa_Azora ***
Ala
ma
kota_Mruczka
ma
psa_Azora
Liczba linii: 5
Liczba znakow: 28
Liczba znakow w 1 linii: 3
Liczba slow: 7
---Tail 1: 
psa_Azora
---Tail 10: 
Ala
ma
kota_Mruczka
ma
psa_Azora
---Head 1: 
Ala
---Head 10: 
Ala
ma
kota_Mruczka
ma
psa_Azora
---UNIQ:
Ala
ma
kota_Mruczka
psa_Azora
---Tail 2: 
ma
psa_Azora

*** dla make test2 = ./main ala_ma_kota ala_ma_kota ***
ala_ma_kota
ala_ma_kota
Liczba linii: 2
Liczba znakow: 22
Liczba znakow w 1 linii: 11
Liczba slow: 6
---Tail 1: 
ala_ma_kota
---Tail 10: 
ala_ma_kota
ala_ma_kota
---Head 1: 
ala_ma_kota
---Head 10: 
ala_ma_kota
ala_ma_kota
---UNIQ:
ala_ma_kota
---Tail 2: 
ala_ma_kota
ala_ma_kota 
*/
  