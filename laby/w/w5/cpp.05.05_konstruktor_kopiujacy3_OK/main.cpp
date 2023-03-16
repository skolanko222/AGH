#include <iostream>
#include <cstring>
using namespace std;

/////////////////////////////////////////////////////////
class Card {
public :
  char *nazw;
  char *imie;

  Card(const char * na, const char * im);
	Card(const Card &K);

  ~Card();

  void print() 
	{ cout << imie << " " << nazw << endl; }

  void SetName(const char *nowe)
  { strcpy(nazw, nowe); }
};
/////////////////////////////////////////////////////////
Card::Card(const char *im, const char *na)
{
  nazw = new char[80];
  strcpy(nazw, na);

  imie = new char[80];
  strcpy(imie, im);
}
/////////////////////////////////////////////////////////
Card::Card(const Card &K)
{
  nazw = new char[80];
	strcpy(nazw, K.nazw);

  imie = new char[80];
	strcpy(imie, K.imie);
}
/////////////////////////////////////////////////////////
Card::~Card()
{
  delete [] nazw;
  delete [] imie;
}
/////////////////////////////////////////////////////////
int main()
{
  Card aCard( "Jan", "Kowalski");
  Card bCard = aCard;

  cout << "Po utworzeniu kopii obiektu oba zwieraja nazwiska\n";

  aCard.print();
  bCard.print();

  bCard.SetName("Nowak");

  cout << "\nPo zmianie nazwiska bCard brzmi ono: ";
  bCard.print();

  cout << "Niemodyfikowany aCard nazywa sie: ";
  aCard.print();
}
