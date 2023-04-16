/*  
Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał a wynik jego działania był taki sam, jak podany na końcu tego pliku. 

Klasa Element reprezentuje element listy jednokierunkowej i posiada prywatne pole wskaźnika na dynamiczną tablicę int oraz wskaźnik na następny element.
Ponadto posiada potrzebne konstruktory i destruktory oraz metody.
  
Klasa MyList i zawiera tylko prywatny wskaźnik na head typu klasy Element oraz publiczne metody:
  * konstruktor - ustawiający wskaźniki na NULL i ew. nadający nazwę (dawne initList),
  * destruktor - usuwający wszystkie elementy listy oraz samą listę,
  * append - wstawia wartość int*  lub Element na koniec listy,
  * removeFirst - usuwa pierwszy element z listy wraz z dealokacją pamięci obiektu typu Element,
  * copyRev - wykonująca kopię listy podanej jako argument.
  
  UWAGA: print jest funkcją zewnętrzną i drukuje listę w postaci [el1, el2, el3],

Należy zadbać o zwolnienie pamięci przy usuwaniu elementów i czyszczeniu listy. Valgrind (make check) nie powinien wykazywać żadnych wycieków pamięci (leap) ani błędów (errors).

Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
Proszę pamietać o dokumentacji kodu.
*/

#include "MyList.h"
#include "Element.h"
#include <iostream>

int main() {
  std::cout << "*** Lista 1 ***" << std::endl;
  MyList list1; 
  int p1[] = {1,2,3};

  Element *pp1=new Element(p1,3); //konstruktor
  pp1->printElem();
  std::cout << std::endl;
  p1[1]=-2;
  list1.append(pp1); //podpinamy element na koniec listy
  std::cout << "Pierwszy: ";
  list1.getHead()-> printElem();
  std::cout << std::endl;
  list1.append(p1,2); //KOPIUJEMY
  p1[0]=-1;
  const int* q1 = p1;
  list1.append(q1,3);
  
  const MyList* ptr1 = &list1;
  std::cout << "Drugi: ";
  ptr1 -> getHead() -> getNext()->printElem();
  std::cout << std::endl;

  const MyList *ptrc=ptr1;
  std::cout << "Czy lista 1 jest pusta? " 
            << (ptrc->isEmpty()?"Tak":"Nie") << std::endl;
  print("Lista1",ptrc);
  
  std::cout << "\n*** Lista 2 ***" <<std::endl;
  std::cout << "1";
  MyList list2;
  list2.copyRev(&list1);
  print("Lista2", &list2);
  
  std::cout << "\n*** Usuwanie po elemencie ***" << std::endl; 
  print("Lista1", &list1);
  list1.removeFirst();
  print("Lista1", &list1);
  list1.removeFirst();
  print("Lista1", &list1);
  list1.removeFirst();
  print("Lista1", &list1);
  list1.removeFirst(); //próba usunięcia z pustej listy
  std::cout << "Czy lista 1 jest pusta? " 
            << (ptrc->isEmpty()?"Tak":"Nie") << std::endl;
  const MyList *plist2=&list2;
  print("Lista2", plist2);
  return 0;
}

/* Oczekiwany wynik: ./main
*** Lista 1 ***
(1,2,3)
Pierwszy: (1,2,3)
Drugi: (1,-2)
Czy lista 1 jest pusta? Nie
Lista1 = <(1,2,3) (1,-2) (-1,-2,3)>

*** Lista 2 ***
Lista2 = <(-1,-2,3) (1,-2) (1,2,3)>

*** Usuwanie po elemencie ***
Lista1 = <(1,2,3) (1,-2) (-1,-2,3)>
Destruktor Element: (1,2,3)
Lista1 = <(1,-2) (-1,-2,3)>
Destruktor Element: (1,-2)
Lista1 = <(-1,-2,3)>
Destruktor Element: (-1,-2,3)
Lista1 = <>
Czy lista 1 jest pusta? Tak
Lista2 = <(-1,-2,3) (1,-2) (1,2,3)>
Destruktor MyList 
Destruktor Element: (-1,-2,3)
Destruktor Element: (1,-2)
Destruktor Element: (1,2,3)
Destruktor MyList 
*/
