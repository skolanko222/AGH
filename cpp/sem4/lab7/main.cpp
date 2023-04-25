// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie związane jest z podstawami dziedziczenia wielokrotnego.  
// W hierarchii wystepuja 4 klasy. Należy poprawnie odwzorowac zależnosci między nimi.
// UWAGA: Klasa bazowa Person nie moze byc interfejsem (czysto wirtualna).
// UWAGA: Operator << zachowuje sie jak, wirtualna metoda, nalezy to rozwiązac przez przekierowania
//        jego funkcjonalnosci do wirtualnej metody.

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
#include "Person.h"
#include "Faculty.h"
#include "Grade.h"
#include "Student.h"

int main() {
  {
    Person m("Jennifer"); // name
    std::cout << "Just Person: " << m  << std::endl;
  }

  {
    Student* s = new Student("Jennifer",1334);  // name, id
    Person *x  = s;  
    std::cout << "Student: "  << *x << std::endl;
    delete x;
  }
  
  {
    Faculty* l = new Faculty("Jennifer","Physics");  // name, spec
    const Person* x  = l;  
    std::cout << "Faculty: "  << *x << std::endl;
    delete x;
  }

  { // przygoda z wielokrotnym dziedziczeniem
    Grade* k = new Grade("Jennifer",1334,"Physics"); // name, id, spec
    Student* s = k;
    Faculty* l = k; l = k = nullptr;
    std::cout << "Grade:\n" << *s << std::endl;    
    delete s;    
  }//*/
}

/* wynik:
Just Person: Person: name: Jennifer 
~Person (Jennifer)
Student: Student: Person: name: Jennifer  id: 1334
~Student (Jennifer, id=1334)
~Person (Jennifer)
Faculty: Faculty: Person: name: Jennifer  spec: Physics
~Faculty
~Person (Jennifer)
Grade:
jako Person: name: Jennifer 
jako Student: Person: name: Jennifer  id: 1334
jako Faculty: Person: name: Jennifer  spec: Physics
~Grade
~Faculty
~Student (Jennifer, id=1334)
~Person (Jennifer
*/