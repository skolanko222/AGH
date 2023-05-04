// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Tematem zadania sa szablony funkcji. 
// Funkcje szablonowe moga byc metodami i moga byc statyczne. 
// 
// Prosze zaimplementowac prostą klasę Punkt która przechowuje składniki:
// nazwę i i współrzędne x, y typu int.
// Klasa posiada metode dostepowa wsp, ktora jest szablonowa i pozwala na dostanie sie
// do wsp. x lub y w zależności od arg szablonowego 0 i 1 odpowiednio.
// Dwa obiekty kl. Punkt mozna porównywać <. Najpierw porównywane są 
// wsp. x a wsp. y tylko gdy x-owe sa rowne:
// return x == rhs.x ? y < rhs.y : x < rhs.x
// W sklad klasy wchodzi również metoda statyczna min. Należy zaprogramować ją w sposob ogólny
// tak by działała dla klasy Punkt i dla typów prostych.
// Na koniec, poza klasą Punkt, należy zaprogramować szablonową metodę swap, 
// oraz jej specjalizację dla klasy Punkt, dla której zamieniane są jedynie współrzędne, bez nazwy.
//
// Pliku main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny 
// i dobrze napisany kod), oraz powinna być spełniona zasada D.R.Y. 
// - Don't Repeat Yourself.
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp 
// należy wgrać do UPEL jako archiwum tar.gz, 
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab09/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "Punkt.h"

int main() {

  Punkt s1("s1",0, 1);
  Punkt s2("s2",-5, 2);

  std::cout << "s1 " << s1.wsp<0>() <<  " " << s1.wsp<1>() << std::endl;
  std::cout << "s2 " << s2.wsp<0>() <<  " " << s2.wsp<1>() << std::endl;
  
  std::cout << "min: " << Punkt::min(s1.wsp<0>(), s2.wsp<0>()) << " " << Punkt::min(s1.wsp<1>(), s2.wsp<1>()) << std::endl;
  std::cout << "min: " << Punkt::min(s1, s2).wsp<0>() << " " << Punkt::min(s1, s2).wsp<1>() << std::endl;

  std::cout << "porownanie: " << std::boolalpha << (s1 < s2) << " " << (s2 < s1) << std::endl;  

  int a = 2, b = 3;
  std::cout << "before swap(int): " << a << " " << b << std::endl; 
  swap<int>(a,b);
  std::cout << "after swap(int): " << a << " " << b << std::endl; 

  std::cout << "before swap(punkt): " << s1 << " " << s2 << std::endl;
  swap<Punkt>(s1,s2); 
  std::cout << "after swap(punkt): " << s1 << " " << s2 << std::endl;


}
/*
s1 0 1
s2 -5 2
min: -5 1
min: -5 2
porownanie: false true
before swap(int): 2 3
after swap(int): 3 2
before swap(punkt): s1(0,1) s2(-5,2)
after swap(punkt): s1(-5,2) s2(0,1)
*/