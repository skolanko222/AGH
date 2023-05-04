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
/////////////////////////////////////////////////////////////////////////
template <typename T, int size>
std::ostream &operator<<(std::ostream &o, const Box<T, size> &K)
{
  for (unsigned i = 0; i < size; ++i)
    o << K.box[i] << " ";
  return o;
}
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  OOP::Box<int, 10> a;
 
  for (int i = 0; i < 10; ++i)
    a[i] = i;

  cout << a << endl;

  a.SetAll(25);
  cout << a << endl;

  OOP::Box<OOP::Fraction, 2> aBoxFrac;

  aBoxFrac.box[0].SetL(1);
  aBoxFrac.box[0].SetM(2);

  aBoxFrac.box[1].SetL(1);
  aBoxFrac.box[1].SetM(5);

  cout << aBoxFrac << endl;

  aBoxFrac.SetAll(OOP::Fraction(12, 43));

  cout << aBoxFrac << endl;

  return 0;
}
