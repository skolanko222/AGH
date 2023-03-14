/*  
  Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał a wynik jego działania był taki sam, jak podany na końcu tego pliku. Zadanie opiera się częściowo na kodzie z zajęć 5 i polega na przekształceniu struktury listy jednokierunkowej w klasę.

  Klasa Element reprezentuje element listy jednokierunkowej i posiada pole typu char* oraz wskaźnik na następny element.
  Ponadto posiada potrzebne konstruktory i destruktory oraz metody.
  
  Klasa MyList i zawiera pola: 
   wskaźniki na head i tail typu klasy Element oraz publiczne metody:
  * konstruktor - ustawiający wskaźniki na NULL i ew. nadający nazwę (dawne initList),
  * destruktor - usuwający wszystkie elementy listy oraz samą listę,
  * clearList - usuwa wszystkie elementy z listy, włącznie ze zwolnieniem pamięci każdego z elementów, ale nie usuwa samej listy,
  * append - wstawia wartość char*  lub Element na koniec listy,
  * removeFirst - usuwa pierwszy element z listy wraz z dealokacją pamięci obiektu typu Element,
  
  UWAGA: print jest funkcją zewnętrzną i drukuje listę w postaci [w1, w2, w3],

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

    Element *agnieszka=new Element("Agnieszka"); //konstruktor
    list1.append(agnieszka); //podpinamy element do listy
    list1.append("Beata");
    list1.append("Maria");

    const MyList* ptr1 = &list1;
    std::cout << "Pierwszy: " << ptr1->getHead()-> getName() << std::endl;
    std::cout << "Ostatni: ";
    ptr1->getLast()->printName();
    std::cout << std::endl;

    const MyList *ptrc=ptr1;
    std::cout << "Czy lista 1 jest pusta? " 
              << (ptrc->isEmpty()?"Tak":"Nie") << std::endl;
    print(ptrc);

    std::cout << "\n*** Lista 2 ***" <<std::endl;
    MyList list2;
    
    Element *kris = new Element("Krzysztof");
    list2.append("Adam");
    list2.append(kris);
    list2.append("Tomasz");
    print(&list2);

    std::cout << "\n*** Usuwanie ***" << std::endl;
    
    std::cout << "--- Usuwam listę element po elemencie" << std::endl;   
    print(&list1);
    list1.removeFirst();
    print(&list1);
    list1.removeFirst();

    std::cout << "--- Usuwam wszystkie elementy hurtem" << std::endl;
    const MyList* ptr2 = &list2;
    print(ptr2);
    list2.clearList();
    list2.clearList(); //próba usunięcia z pustej listy
    std::cout << "Czy lista 2 jest pusta? " 
              << (ptr2->isEmpty()?"tak":"nie") << std::endl;
    std::cout << "--- Nazwa nadal istnieje, ale nie ma elementow" << std::endl;     
    print(&list2);
    
    return 0;
}

/* Oczekiwany wynik: ./main
*** Lista 1 ***
Pierwszy: Agnieszka
Ostatni: Maria
Czy lista 1 jest pusta? Nie
[Agnieszka Beata Maria]

*** Lista 2 ***
[Adam Krzysztof Tomasz]

*** Usuwanie ***
--- Usuwam listę element po elemencie
[Agnieszka Beata Maria]
Destruktor Element: Agnieszka
[Beata Maria]
Destruktor Element: Beata
--- Usuwam wszystkie elementy hurtem
[Adam Krzysztof Tomasz]
Destruktor Element: Adam
Destruktor Element: Krzysztof
Destruktor Element: Tomasz
Czy lista 2 jest pusta? tak
--- Nazwa nadal istnieje, ale nie ma elementow
[]
Destruktor MyList
Destruktor MyList
Destruktor Element: Maria
*/
