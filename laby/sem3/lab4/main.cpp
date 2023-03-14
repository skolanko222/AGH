/* 
 Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał, a wynik jego działania był taki sam, jak podany na końcu tego pliku.

Klasa MapPoint (pliki MapPoint.h, MapPoint.cpp) reprezentuje punkt na mapie składający się z nazwy, długości (longitude) i szerokości (latitude) geograficznej i nic więcej.
 
Konstruktor klasy oraz funkcja setPoint ustawia wartości składowe - przyjmuje dodatnie i ujemne wartości wspórzędnych i na ich podstawiew print wnioskujemy strony świata. Odpowiednio zgodnie z układem współrzędnych dla długości ujemnych mamy W, a dla szerokości ujemnych mamy S.
Kiedy dodatkowo w setPoint podamy strony świata, nie zapamietujemy ich w obiekcie klasy tylko w razie potrzeby zmieniamy wartości na ujemne.

Wszystkie elementy składowe klasy mają być PRYWATNE, definiujemy odpowiednie metody get i set (ciała tych fukcji mogą być w pliku nagłówkowym). Proszę zwrócić uwagę na obiekty const.
Nalezy samemu zdecydować, które funkcje mają być składowa a które zewnętrzne, operujące na obiektach klasy. Nie definiujemy funkcji zaprzyjaźnionych.

Funkcja inTheMiddle powinna tworzyć i zwracać nowy punkt na mapie o zadanej nazwie i położeniu, które jest średnią arytmetyczną z położeń podanych punktów czyli x = (x1 + x2)/2 itp. Proszę uważać w przypadku różnych półkul.

Funkcja distance oblicza pierwiastek z sumy kwadratów odległości względem południków i równoleżników, czyli sqrt(delta_x*delta_x + delta_y*delta_y).

WSKAZÓWKI:
Nazwa może być typu std::string
Funkcja obliczająca pierwiastek nazywa się: sqrt(double) i znajduje się w bibliotece "cmath".
Do obliczenia wartości bezwzględnej można wykorzystać fabs(double)
Zachęcam do stosowania skróconej wersji if:
cout << (a<b? "mniejsze": "większe");
a = (a<b ? a: b);

Pliku main.cpp, nie wolno modyfikować.
*/


#include <iostream>
#include "MapPoint.h"

int main() {
  const double longitude = 19.938333;
  const double latitude = 50.061389;
  MapPoint krakow;
  krakow.setPoint("Krakow", longitude, latitude); //kierunki E N
  krakow.print();
  const MapPoint nyc("Nowy Jork", -74.0059, 40.7127); //kierunki W N
  std::cout << "Nowy Jork: " << nyc.getLongitude() << ", " << nyc.getLatitude() << std::endl;
  nyc.print();
  MapPoint sydney;
  sydney.setPoint("Sydney", 151.102,'E', 33.454, 'S'); // nie przechowujemy w klasie E i S tylko zmieniamy znak
  std::cout << "Sydney: " << sydney.getLongitude() << ", " << sydney.getLatitude() << std::endl;
  sydney.print();
  MapPoint porto("Porto", 41.162142, 8.621953); // kierunki E N
  const MapPoint * portugalCity = &porto;
  portugalCity->print();

  const double longitudeShift = 4.1234;
  const double latitudeShift = -25.987;
  std::cout << "*** Po przesunieciu ***\n";
  porto.move(longitudeShift, latitudeShift);
  porto.print();
  std::cout << "*** Po przesunieciu ***\n";
  porto.move(-90.5710, 34.7300);
  portugalCity->print();

  std::cout <<"Odleglosci między NYC i Sydney: "  << distance(nyc,sydney) << std::endl;
  const MapPoint * cl = closestPlace(krakow, nyc, sydney);
  std::cout << "Blizej Krakowa jest " << cl->getName() << std::endl;
  MapPoint mp = inTheMiddle(&nyc, &sydney, "Kenia");
  mp.print();
}

/** Wynik działania programu:
./main
Wspolrzedne dla Krakow: 19.9383E, 50.0614N
Nowy Jork: -74.0059, 40.7127
Wspolrzedne dla Nowy Jork: 74.0059W, 40.7127N
Sydney: 151.102, -33.454
Wspolrzedne dla Sydney: 151.102E, 33.454S
Wspolrzedne dla Porto: 41.1621E, 8.62195N
*** Po przesunieciu ***
Wspolrzedne dla Porto: 45.2855E, 17.365S
*** Po przesunieciu ***
Wspolrzedne dla Porto: 45.2855W, 17.365N
Odleglosci między NYC i Sydney: 237.011
Blizej Krakowa jest Nowy Jork
Wspolrzedne dla Kenia: 38.5481E, 3.62935N
*** Koniec ***
*/