/* 
 Proszę zdefiniować klasy: 
 * Point2D - klasa reprezentująca punkt na plaszczyznie (x,y), dodatkowo trzeba zdefiniować dla niej:
   - operatory post/pre inkrementacji,
   - przeciążyć operatory new oraz delete, tak aby w przypadku tworzenia/czyszczenia wskaźnika wyświetlana byla informacja o tym fakcie na ekran (jak w przykladzie wydruku ponizej)
   Wskazówka:
   - typ size_t  (argument new) zdefiniwany jest w stddef.h
   - standardowe new używamy z operatorem zakresu (::new) 

 * Point2DSmartPtr - klasa będąca opakowaniem dla normalnych wskaźników na typ Point2D zapewniająca wobec nich dodatkowe zachowanie:
   - w destruktorze klasy Point2DSmartPtr wywolany jest operator delete, dzieki czemu klasa ta moze służyć do bezpiecznego obchodzenia się z pamięcią.
    Wskazówka: należy przeciążyć operator do operacji na wskaźnikach (->)

 * PointAverage - klasa stanowiąca obiekt funkcyjny (funktor), obliczający średnią arytmetyczną z podanych Point2D (średnia arytmetyczna osobno dla x i y) i aktualizujący wynik z każdym kolejnym wywołaniem.
   Metoda reset() resetuje stan funktora.
*/


#include <iostream>
#include "Point2DSmartPtr.h"
#include "PointAverage.h"

int main() {

  std::cout << "*** Arytmetyka ***"<< std::endl;

  Point2D point1(1.2, 0.5), point2(0.8, 0.5), point3;
  point3 = 0.5 + point1 + point2;
  point1.print();
  (--point2).print();
  (point3++).print();

  Point2DSmartPtr s_point = new Point2D(0.5, 1.2);
  s_point->print();

  std::cout << "\n*** Srednia ***"<< std::endl;
  PointAverage average;

  average(point1);
  average(point2);
  average(point3);
  average.print();

  average.reset();

  average(point1);
  average(point2);
  average.print();
	
  return 0;
}
/* Oczekiwany wynik

*** Arytmetyka***
Point2D:: (1.2,0.5)
Point2D:: (-0.2,-0.5)
Point2D:: (2.5,1)
Point2D:: alokowanie 16 bajtow
Point2D:: (0.5,1.2)

*** Srednia ***
Average Point:: (1.5,0.666667)
Average Point:: (0.5,0)
Point2D:: zwalnianie wskaznika

*/
