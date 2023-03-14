// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasę MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z nazwy, dlugosci (longitude) i szerokosci
// (latitude) geograficznej bez oznaczania polkol.

// Metoda mp.distanceVal(dest) zwraca moduł z punktu tworzonego 
// przez różnicę położeń z podanych punktów czyli x_new = dest.x - mp.x, itd.

// Składowa klasy MapPoint::NMapPoinst przechowuje informacje o wszystkich 
// utworzonych punktach (każda nowa instancja klasy inkrementuje tą zmienną).

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab05/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "MapPoint.h"

int main() {
  using std::cout;

  cout<<"========== KRK & NYC ==========\n";
  MapPoint krk(19.9383,50.0613);    // # 1
  MapPoint nyc(40.7127,-74.0059);   // # 2
  krk.print();
  nyc.print();

  cout<<"========== PORTO & Null Island ==========\n";
  MapPoint porto(41.1621, -8.6219); // # 3
  const MapPoint nullIsland;        // # 4
  porto.print();
  nullIsland.print();

  cout<<"========== DISTANCE ==========\n";
  cout<<"PRT-Null: "<<nullIsland.distanceVal(porto) << std::endl;   // # 5

  cout<<"========== COPY & STAT ==========\n";
  MapPoint cpyNullIsland(nullIsland);   // # 6
  cout<<"<N> MapPoints : "<< MapPoint::NMapPoint << std::endl;


  return 0;
}
/** Wynik dzialania programu:
========== KRK & NYC ==========
Point: (19.9383, 50.0613)
Point: (40.7127, -74.0059)
========== PORTO & Null Island ==========
Point: (41.1621, -8.6219)
Point: (0, 0)
========== DISTANCE ==========
PRT-Null: 42.0554
========== COPY & STAT ==========
<N> MapPoints : 6
*/
