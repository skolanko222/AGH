// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Proszę zaimplementować klasy, założeniami:
// MyString:
// -  do przechowywania napisu (można skorzystać lub nie z std::string)
// -  klasa posiada odpowiednio przeładowane operatory new i delete (w tym świczeniu chodzi od komunikat na std::cout)
// MyStringContainer:
// - do przechowywania instancji MyString w formie surowych wskaźników
// - klasa domyślnie przechowuje obiekty funkcyjne które mogą służyć do sortowania np w ramach std::sort
//   powyższe obiekty funkcyjne są to Less oraz Greater do porównywania MyString (z poprzednich zajęć) 
// - obiekty funkcyjne są przechowywane np w std::vector z wykorzysyaniem std::function
// 
// Dodatkowe wskazówki wykonania zadania znajdują się w definicji funkcji main,
// PrintNames jest globalną metodą do drukowania na ekran imion przechowywanych w kontenerze

// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod), oraz powinna być spełniona zasada
// D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab02/
// * archiwum nie powinno zawierać katalogu build/


#include <iostream>
#include "StringFun.h"

int main() {

  // MyString z przeładowanymi operatorami new i delete, w tym przypadku drukujący jedynie dodatkowy komunikat
  auto namePtr = new MyString("Abigale");

  // Contener na MyString przechowujący je w postaci surowych wskaźników
  MyStringContainer msc;  
  msc.AddMStr(namePtr);   // za pomocą metody  MyStringContainer::AddMStr rejestrujemy kolejne wskaźniki
  msc.AddMStr("Antonio"); // ups... tutaj napis, ale na podstawie którego robimy odpowiedni typ.

  auto sortedAsc = msc.GetSorted("ASC"); // zwracamy std::vector<MyString> alfabet. uporządkowanych imion > ascending names
  PrintNames(sortedAsc);

  auto sortedDesc = msc.GetSorted("DESC"); // // zwracamy std::vector<MyString> alfabet. uporządkowanych imion > descending names
  PrintNames(sortedDesc);

  std::cout << "Preparing the backup:" << std::endl;
  MyStringContainer msc_bkp = msc;

  // Operacje na napisach przechowywanych w  std::vector, oraz z wykorzystaniem funktorów:
  std::vector<MyString> names = { "Abe", "Andrew", "Aaron", "Arthur", "Alfred", "Al", 
                                  "Abdul", "Adrian", "Albert", "Alessandro" };

  for (const auto& func : msc_bkp.SortFunc() ){     // MyStringContainer::SortFunc zwraca vector funktorów
    std::sort( names.begin(), names.end(), func );
    PrintNames(names);
  }
  
  return 0;  
}
/* wynik:
[MyString] Overloading new operator with size: 32
[MyString] Overloading new operator with size: 32
Abigale Antonio 
Antonio Abigale 
Preparing the backup:
[MyString] Overloading new operator with size: 32
[MyString] Overloading new operator with size: 32
Aaron Abdul Abe Adrian Al Albert Alessandro Alfred Andrew Arthur 
Arthur Andrew Alfred Alessandro Albert Al Adrian Abe Abdul Aaron 
[MyString] Overloading delete operator 
[MyString] Overloading delete operator 
[MyString] Overloading delete operator 
[MyString] Overloading delete operato
*/