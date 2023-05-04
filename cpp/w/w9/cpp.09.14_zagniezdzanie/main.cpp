#include "Fraction.h"
#include "OOPFunTemplates.h"
#include <exception>
#include <iostream>

namespace OOP {

template <typename T, unsigned rozmiar> class Box
{
public:
  /////////////////////////////////////////////////////////////////////////
  class BoxError : public std::exception
  {
  public:
    BoxError(T obj) : dana(obj)
    {
    }

    const char *what() const throw()
    {
      return "Wyjatek BoxError.";
    }

    T dana;
  };
  /////////////////////////////////////////////////////////////////////////

  T box[rozmiar];
  Box() : m_size(rozmiar)
  {
  }

  T &operator[](unsigned i) ;

  void SetAll(const T &obj);

private:
  unsigned m_size;
};
/////////////////////////////////////////////////////////////////////////
template <typename T, unsigned rozmiar>
T &Box<T, rozmiar>::operator[](unsigned i) 
{
  if (i < m_size)
    return box[i];
  else
    throw BoxError(box[0]);
}
/////////////////////////////////////////////////////////////////////////
template <typename T, unsigned rozmiar>
void Box<T, rozmiar>::SetAll(const T &obj)
{
  for (unsigned i = 0; i < m_size; ++i)
    box[i] = obj;
}
/////////////////////////////////////////////////////////////////////////
template <typename T, unsigned size>
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

  try
  {
    OOP::Box<OOP::Box<int, 1>, 10> a;

    for (int i = 0; i < 10; ++i)
      a.box[i].box[0] = i;

    cout << a << endl;

    OOP::BoxOpis<double> b;

    b.SetT(3.14159);
    b.SetOpis("M_PI");

    cout << b << endl;

    // z³y zakres wyrzuci wyj¹tejk OOP::Box<int, 1>::BoxError
    a[4][5] = 0;

    // ale takie u¿ycie nie wyrzuci wyj¹tku
    // a.box[4].box[5] = 0;
  }
  catch (const OOP::Box<int, 1>::BoxError &e)
  {
    cout << e.what() << " Dana = " << e.dana << endl;
  }
  return 0;
}
