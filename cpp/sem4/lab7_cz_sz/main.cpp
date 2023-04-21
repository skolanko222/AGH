// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie związane jest z podstawami dziedziczenia wielokrotnego.  
// W hierarchii wystepuja 4 klasy. Należy poprawnie odwzorowac zależnosci między nimi.
// UWAGA: Klasa bazowa Mebel nie moze byc interfejsem (czysto wirtualna).
// UWAGA: Operator << zachowuje sie jak, wirtualna metoda, nalezy to rozwiązac przez przekierowania
//        jego funkcjonalnosci do takiej wlaśnie wirtualnej metody.

// Prosze zadbac o dobre zarzadzanie pamiecia.
// Pliku main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab07/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "Mebel.h"
#include "Sofa.h"
#include "Lozko.h"
#include "Kanapa.h"

int main() {
  {
    Mebel m(100, 120, 150); // sz, wys, dl
    std::cout << "Just mebel: " << m  << std::endl;
  }

  {
    Sofa* s = new Sofa(90, 100, 200, 180);  // sz, wys, dl, szer_siedziska
    Mebel *x  = s;  
    std::cout << "Any sofa: "  << *x << std::endl;
    delete x;
  }
  
  {
    Lozko* l = new Lozko(90, 100, 200, 190);  // sz, wys, dl, szer_spania
    const Mebel* x  = l;  
    std::cout << "King bed: "  << *x << std::endl;
    delete x;
  }

  { // przygoda z wielokrotnym dziedziczeniem
    Kanapa* k = new Kanapa( 80, 90, 220, 195, 200); // sz, wys, dl, szer_siedziska, szer_spania
    Sofa* s = k;
    Lozko* l = k; l = k = nullptr;
    std::cout << "Kanapa from Ikea:\n" << *s << std::endl;    
    delete s;    
  }
}

/* wynik:
Just mebel: Mebel: sz: 100 wys: 120 dl: 150 
~Mebel
Any sofa: Sofa: Mebel: sz: 90 wys: 100 dl: 200  siedzisko: 180
~Sofa
~Mebel
King bed: Lozko: Mebel: sz: 90 wys: 100 dl: 200  sz.spania: 190
~Lozko
~Mebel
Kanapa from Ikea:
jako Mebel: sz: 80 wys: 90 dl: 220 
jako Sofa: Mebel: sz: 80 wys: 90 dl: 220  siedzisko: 195
jako Lozko: Mebel: sz: 80 wys: 90 dl: 220  sz.spania: 200
~Kanapa
~Lozko
~Sofa
~Mebel
*/