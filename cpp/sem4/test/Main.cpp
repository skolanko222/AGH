// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Prosze napisac klasy Named, Point oraz PointSmartPtr
// 1) Klasa Named jest jedynie odpowiedzialna za przechowywanie nazwy, ale posiada ona przeciążenie
// operatora >> aby przyjmować napis do ustawiania wartości dla jej jedynego atrybutu.

// 2) Klasa Point dziedziczy po Named oraz przechowuje współrzędne x i y. Posiada operator postinkrementracji,
// oraz dodatkowo, istenieje dla niej przeciążenie operatora << na standardowe wyjście.
// 
// 3) Klasa PointSmartPtr reprezentuje tzw. zwinny wskaźnik dla klasy Point.
// Uwaga: to szczególny przypadek mechanizmu tzw. smart pointerów, tutaj dla klasy Point.
// Konstrukcja PointSmartPtr opiera się na przechowywaniu zasobów:
// Point*, oraz int*. Atrybut typu int jest inkrementowany jeśli powstają kolejne kopie 
// obiektu PointSmartPtr, oraz deikrementowany jeśli kolejna instancja tej klasy jest
// niszczona. Jeśli ten licznik wynosi 0 (to tym samym ginie ostatni obiekt tej klasy)
// zasoby Point*, oraz int* są niszczone. Mechanizm ten warto zaimplementować w specjalnej
// metodzie np. release() która może być wykorzystana nie tylko w destruktorze tej klasy

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
// * archiwum powinno zawierać katalog z zadaniem, np. lab01/
// * archiwum nie powinno zawierać katalogu build/


#include <iostream>
#include "PointSmartPtr.h"

int main() {
  Named named;
  std::cout << "Named " << named.Name() << std::endl;
  "SuperPoint1" >> named;
  std::cout << "Named " << named.Name() << std::endl;

  Point p;
  "SuperPoint2 ">> p;
  std::cout << "main scope... " << p << std::endl;
  PointSmartPtr p_sptr1(new Point(1,1));
  PointSmartPtr p_sptr2 = p_sptr1;
  std::cout << "still in main scope... " << *p_sptr1 << std::endl;
   {
     PointSmartPtr p_sptr3(new Point(2,2,"SuperPoint3"));
    std::cout << "internal scope... " << (*p_sptr3)++ << std::endl;
     p_sptr1 = p_sptr3;
     std::cout << "end of the internal scope... " << *p_sptr1 << std::endl;
   }
   //std::cout << "back again in the main scope... " << *p_sptr1 << std::endl;
  // "WhoAmI" >> (*p_sptr2);
  // std::cout << "end of the main scope... " << *p_sptr2 << std::endl;
}
/* wynik:
Named None
Named SuperPoint1
main scope... SuperPoint2  [0,0]
still in main scope... None [1,1]
internal scope... SuperPoint3 [2,2]
end of the internal scope... SuperPoint3 [3,3]
back again in the main scope... SuperPoint3 [3,3]
end of the main scope... WhoAmI [1,1]
*/
