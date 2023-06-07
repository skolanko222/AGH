/* 
Celem projektu jest napisanie polimorficznej listy przechowujacej dane jako wartosci.

W sklad takiej listy wchodzą elementy Node, które muszą byc dostosowane do różnych typów przechowywanych. 
Czyli gdzieś w środku musi byc typ: Node<int> Node<flaot> -> narzuca sie odpowiednia hierarchia
-> szablonowa klasa TNode

UWAGA: Wirtualne zachowanie potrzebne w implementacji isType mozna uzyskać po zamanie typu na jego identyfikator (RTTI)
UWAGA: Dokumentacja mechanizmu RTTI: http://en.cppreference.com/w/cpp/language/typeid

W przypadku "metody" get zkladamy ze typy pasuja (mozna to sprawdzic za pomoca isType) 
a wiec mozna wykonac odpowiednie rzutowanie.
UWAGA: Proszę nie zapomniec o sprzatnieciu pamieci (virtual ~).
 */

#include <iostream>
#include "List.h"

int main() {
  List al;
  al.add<int>(7);
  al.add<float>(3.56);    // dodaje na poczatku
  al.add<double>(4.566);  // to jest teraz pierwsza

  std::cout << std::boolalpha << al.head()->isType<int>()  << std::endl;
  std::cout << al.head()->isType<int>()  << std::endl;

  const TNode<double>* fd = dynamic_cast<const TNode<double>*>( al.head() );
  fd ? std::cout << fd->get() << std::endl : std::cout << " to nie double... "  << std::endl;

  const TNode<int>* fi = dynamic_cast<const TNode<int>*>( al.head() );
  fi ? std::cout << fi->get() << std::endl : std::cout << " to nie int... "  << std::endl;

  std::cout << al.head()->next()->isType<float>()  << std::endl;
  std::cout << al.head()->next()->isType<int>()  << std::endl;
  std::cout << al.head()->next()->next()->isType<int>()  << std::endl;

  // std::cout << List::get<double>(al.head()) << std::endl;  // pierwszy jest double
  // std::cout << List::get(al.head()) << std::endl;          // jak to działa?*/
  
}
/* wynik
false
false
4.566
 to nie int... 
true
false
true
4.566
4.566
 */