#include "Fraction.h"
#include "OOPFunTemplates.h"
#include <exception>
#include <iostream>

namespace OOP {

template <typename T, int rozmiar> class Box
{
public:
  T box[rozmiar];
  Box() : m_size(rozmiar)
  {
  }

  T &operator[](unsigned i) ;

  void SetAll(const T &obj);

  void printOn();

private:
  unsigned m_size;
};
/////////////////////////////////////////////////////////////////////////
template <typename T, int rozmiar> void Box<T, rozmiar>::printOn()
{
  for (unsigned i = 0; i < m_size; ++i)
    std::cout << box[i] << " ";

  std::cout << std::endl;
}
/////////////////////////////////////////////////////////////////////////
template <typename T, int rozmiar>
T &Box<T, rozmiar>::operator[](unsigned i) 
{
  if (i < m_size)
    return box[i];
  else
    throw std::range_error("Przekroczony zakres");
}
/////////////////////////////////////////////////////////////////////////
template <typename T, int rozmiar> void Box<T, rozmiar>::SetAll(const T &obj)
{
  for (unsigned i = 0; i < m_size; ++i)
    box[i] = obj;
}
/////////////////////////////////////////////////////////////////////////
template <typename T, int size>
std::ostream &operator<<(std::ostream &o, const Box<T, size> &K)
{
  for (unsigned i = 0; i < size; ++i)
    o << K.box[i] << " ";
  return o;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
template <typename T> class BoxOpis
{
public:
  Box<T, 1> boxT;

  void SetT(const T &obj)
  {
    boxT.box[0] = obj;
  }
  void SetOpis(const std::string opis)
  {
    this->opis = opis;
  }

  std::string opis;
};
/////////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream &operator<<(std::ostream &o, const BoxOpis<T> &K)
{
  o << K.opis.c_str() << ": " << K.boxT;
  return o;
}

} // End of namespace

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  OOP::Box<OOP::Box<int, 1>, 10> a;

  for (int i = 0; i < 10; ++i)
    a.box[i].box[0] = i;

  cout << a << endl;

  OOP::BoxOpis<double> b;

  b.SetT(3.14159);
  b.SetOpis("M_PI");

  cout << b << endl;
  return 0;
}
