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
// UWAGA: Defnicja co najmniej jednej metoda z klasy powina być przeniesiona poza klasę!
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
  a.reset(5.1); // ustawia wszystkie wartosci na 5.1
  
  Matrix<double, 3, 3> b;
  
  // a.add(b);  // to się niepowinno kompilować 
                //- rozmiary a i b sa rożne i byłoby to dzialanie niejednoznaczne 

  // dostęp do składowych poprzez standardowe metody
  b.at(1,1) = 2.5;
  b.at(1,2) = 3.1;
  
  // dostęp do składowych poprzez metody szablonowe
  std::cout << b.at<1,1>() << " " << a.at<0,2>()  << std::endl;
  
  Matrix<int, 3, 3> c(1); // parametr ctr'a ustawia wszystkie wartości na 1
  c.at<2,0>() = 7;
  b.add(c); // a to sie kompiluje bo wymiary sa takie same, moimo ze typy sa różne
  std::cout << std::setprecision(2) << std::fixed << "b+c=\n" << b; // */
}
/* wynik
2.5 5.1
b+c=
1.00 1.00 7.00 
1.00 3.50 1.00 
1.00 4.10 1.00
 */
