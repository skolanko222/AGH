/* Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywał sie, a wynik jego działania był taki sam jak podany na końcu pliku.

Proszę napisać klasę MapPoint, ktora reprezentuje punkt na mapie, każdy tworzony punkt ma swój unikatowy numer ID, współrzędne i nazwę.
Nowy punkt można tworzyć za pomocą różnych konstruktorów albo funkcji makePoint (raz zdefiniowana).
Prosze stosować listy inicjalizacyjne i konstruktory delegowane, ich uzycie wpływa na ocenę kodu.

Metoda setPoint ustawia dlugosc i szerokosc geograficzną oraz nazwę punktu, jeśli jest podana na podstawie argumentow, ktore przyjmuje. Postaraj się napisać tylko jedną funkcję setPoint.

Funkcja distance w klasie MapPoint zwraca obiekt typu MapDistance, ktory przechowuje informacje o różnicy pomiędzy długościami
geograficznymi dwóch punktów oraz różnicy pomiędzy szerokościami  geograficznymi tych samych punktów.

Metoda inTheMiddle powinna tworzyć i zwracać nowy punkt na mapie o zadanej nazwie i położeniu, które jest średnią arytmetyczną z położeń podanych punktów czyli x = (x1 + x2)/2 itp. Proszę uważać w przypadku różnych półkul. 

 Pliku main.cpp, nie wolno modyfikowac.
*/


#include <iostream>
#include "MapPoint.h"
#include "MapDistance.h"
//#include "MapPoint.h"
#include "MapDistance.h"

int main() {
  using std::cout;
  cout << "Liczba punktów: " << getObjects() <<std::endl;
  //{
  cout<<"========== KRK ==========\n";
  MapPoint krk;
  krk.print();
  krk.setName("Krakow");
  krk.setLatitude(19.938333);
  krk.setLongitude(50.061389);
  krk.print();

  cout<<"========== NYC ==========\n";
  const double nyc_latitude = 40.7127;
  const double nyc_longitude = -74.0059;
  MapPoint nyc;
  nyc.setName("Nowy Jork");
  nyc.setPoint (nyc_latitude, nyc_longitude);
  nyc.print();

  cout<<"========== PORTO I IRKUCK ==========\n";
  MapPoint porto = MapPoint::makePoint(41.162142, -8.621953,"Porto");
  /*porto.print();
  MapPoint irkuck = MapPoint::makePoint(52.283333, 104.283333);
  irkuck.setName("Irkuck");
  irkuck.print();
  cout << "Liczba punktów: " << getObjects() <<std::endl;
  cout<<"========== NOWE MIEJSCE ==========\n";
  MapPoint sydney = porto;
  sydney.print();
  sydney.makePoint(151.102, -33.454, "Sydney");
  sydney.setPoint(151.102, -33.454,"Sydney");
  sydney.print();
  krk.inTheMiddle(nyc).print();

  cout<<"========== ODLEGLOSC ==========\n";
  cout << "Odleglosc Nowy Jork - Krakow:\n";
  MapDistance nyc_krk = nyc.distance(krk);
  nyc_krk.print();
  cout << nyc_krk.distance() << std::endl;
  cout << "Odleglosc Sydney - Krakow:\n";
  MapDistance sydney_krk = sydney.distance(krk);
  sydney_krk.print();
  cout << sydney_krk.distance() << std::endl;
  cout << "Blizej Krakowa jest:\n";
  krk.closestPlace(sydney,nyc).print();
  }
  cout << "Liczba punktów: " << getObjects() <<std::endl;*/
  return 0;
}
/** Wynik dzialania programu:

Liczba punktów: 0
========== KRK ==========
Punkt nr 1: Punkt (0, 0)
Punkt nr 1: Krakow (19.9383, 50.0614)
========== NYC ==========
Punkt nr 2: Nowy Jork (40.7127, -74.0059)
========== PORTO I IRKUCK ==========
Punkt nr 3: Porto (41.1621, -8.62195)
Punkt nr 4: Irkuck (52.2833, 104.283)
Liczba punktów: 4
========== NOWE MIEJSCE ==========
Punkt nr 5: Porto (41.1621, -8.62195)
Punkt nr 5: Sydney (151.102, -33.454)
Punkt nr 6: Punkt (30.3255, -11.9723)
========== ODLEGLOSC ==========
Odleglosc Nowy Jork - Krakow:
Odleglosc: (124.067, -20.7744)
125.795
Odleglosc Sydney - Krakow:
Odleglosc: (83.5154, -131.164)
155.495
Blizej Krakowa jest:
Punkt nr 2: Nowy Jork (40.7127, -74.0059)
Liczba punktów: 0
*/
