// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest napisanie szablonu klasy reprezentujacej macierz 2D.
// UWAGA: charakterystyczne jest to, że w takim przypadku rozmiary macierzy 
// zadawane sa w czasie kompilacji. Tym samym Matrix<double, 2, 2> i Matrix<double, 3, 3>
// sa roznymi typami!
// Dostęp do elemetow macierzy realizowany jest również poprzez metode szabolonowa at<...>()
// ktorej argumentami sa indeksy macierzy.
//
// Funkcja add(...) dodaje do siebie macierze tego samego wymiaru (inaczej jest błąd kompilacji).
// Funkcja ta jednak pozwala przyjać argument innego typu (tu tablica int) i dodac do tablicy double.
// Inaczej mowiąc, tablicę o tym samym rozmiarze i róznym typie przechowywanym można dodawać.
// 
// Funkcja get_transpose(...) zwraca nową odwróconą względem diagonali macierz;
// Tutaj można założyć że transpozycja odbywa się jedynie na macierzach kwadratowych;
//
// UWAGA: Defnicja co najmniej jednej metody szablonowej z klasy powina być przeniesiona poza klasę!
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
// * archiwum powinno zawierać katalog z zadaniem, np. lab11/
// * archiwum nie powinno zawierać katalogu build/

#include <iomanip>  // std::setprecision
#include <iostream>
#include "Matrix.h"


int main() {

  Matrix<double, 2, 3> a;
  std::cout << "a=\n" << a << std::endl;

  Matrix<int, 3, 3> b(5);  // parametr ctr'a ustawia wszystkie wartości na 5
  std::cout << "b=\n" << b << std::endl;
  
  // a.add(b);  // to niepowinno się kompilować 
                //- rozmiary a i b sa rożne i byłoby to dzialanie niejednoznaczne 

  // dostęp do składowych poprzez standardowe metody
  b.at<1,1>() = 4;

  // dostęp do składowych poprzez metody szablonowe
  std::cout << "a[0,2]=" << a.at(0,2) << " b[1,1]=" << b.at(1,1) << std::endl;
  
  Matrix<double, 3, 3> c; 
  c.reset(1); // ustawia wszystkie wartosci na 1
  c.at<2,0>() = 4;
  auto d = c.get_transpose(); // zwraca macierz odwróconą względem diagonali
  d.add(b); // a to sie kompiluje bo wymiary sa takie same, moimo że typy sa różne
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << "\nc=\n" << c << "\nd=\n" << d;
}
/* wynik
a=
0 0 
0 0 
0 0 

b=
5 5 5 
5 5 5 
5 5 5 

a[0,2]=0 b[1,1]=4

c=
1.00 1.00 4.00 
1.00 1.00 1.00 
1.00 1.00 1.00 

d=
6.00 6.00 6.00 
6.00 5.00 6.00 
9.00 6.00 6.00
 */