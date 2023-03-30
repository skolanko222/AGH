// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
// Celem zadania jest implementacja tzw. wzorca "wizytujący".
// W tym przykladze obiekty, które wizytator bedzie odwiedzał, sa dwóch typóww int lub float 
// zapakowane w odpowiednie klasy. Ich implementacje sa zadane w pliku Data.h
// Nalezy napisać implementacje PrintingVisitor i AccumulatingVisitor (+ oczywiście dodatkową klasę bazową Visitor).
// UWAGA: Wizytator musi posiadac implementacje methody visit odpowiednie !!DLA KAZDEJ KONKRETNEJ KLASY!!
// ... poniewaz w każdej z nich dostep do danych odbywa sie za pomoca innej metody.
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
// * archiwum powinno zawierać katalog z zadaniem, np. lab05/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "Data.h"
#include "PrintingVisitor.h"
#include "AccumulatingVisitor.h"

int main() {
  FloatData d1( 6.56 );
  IntData d2( 99 );

  const PrintingVisitor print;
  d1.accept( print ); // -> accept PrintingVisitor
  d2.accept( print );
  std::cout << std::endl;
  d1 << 0.98;
  d2 << 3;

  d1.accept( print );
  d2.accept( print );
  std::cout << std::endl;
  
  AccumulatingVisitor accumulate;
  d1.accept( accumulate );  // -> accept AccumulatingVisitor
  d2.accept( accumulate );
  std::cout << accumulate.getTotalSum() << std::endl;
}
/* wynik
 6.56 99
 0.98 3
3.98
 */