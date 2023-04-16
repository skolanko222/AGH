/* 
Celem zadania jest przećwiczenie konwersji jawnych i niejawnych oraz jak im zapobiegać.
Proszę zdefiniować klasy Wymierne i Wektor, reprezentujące odpowiednio  liczby wymierne (licznik/mianownik) oraz wektor (x, y,z). Wszystkie pola są prywatne, nie zaprzyjaźniamy klas.

UWAGA!!!
Klasy te obsługują odpowiednie kowersje między typami. W zadaniu trzeba zdefiniować zarówno operatory, jak i konstruktory konwertujace.
Konstruktory z listami inicjalizacyjnymi  (inline), funkcje get i set proszę zdefiniowac w pliku nagłówkowym w ciele klasy.

Blok ERROR ma się nie kompilować i zgłaszać błąd - odkomentuj linię #define ERROR (za brak -1 pkt)
Proszę nie zapomnieć o dokumentacji. Można stosować krótką formę (samo brief, czyli ///)

Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod), oraz powinna być spełniona zasada DRY - Don't Repeat Yourself
*/

#include"Wektor.h"
#include"Wymierne.h"
#include <iostream>

// #define ERROR 

int main ()
{
  Wymierne liczba (1, 2);
  liczba.print();
  std::cout << std::endl;
  
  Wektor Vec1;
  Vec1.SetX(1, 4).SetY(5, 1).SetZ(1, 6);
  Vec1.print();
  // zmiana pierwszej wspolrzednej
  Vec1.getX() = Wymierne(3, 8);
  Vec1.print();
  Vec1.getX().print();
  std::cout << std::endl;

#ifdef ERROR
  double real0 = Vec1.X(); // error: cannot convert ‘Wymierne’ to ‘double’
#endif

  double real1 = static_cast<double>(Vec1.getX());
  std::cout << "Rzeczywista 1: "<< real1 << "\n";
  double real2 = Wymierne::ToDouble(Vec1.getX());
  std::cout << "Rzeczywista 2: "<< real2 << "\n";

  Wektor Vec2 = 2; // konwersja niejawna
  Vec2.print();

  Wektor Vec3 = liczba;
  Vec3.print();
}

/* wynik dzialania ./main:

1/2
[1/4, 5, 1/6]
[3/8, 5, 1/6]
3/8
Rzeczywista 1: 0.375
Rzeczywista 2: 0.375
[2, 2, 2]
[1/2, 1/2, 1/2]
*/
