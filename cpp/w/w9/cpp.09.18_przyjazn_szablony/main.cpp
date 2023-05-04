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
  friend std::ostream &operator<<(std::ostream &o, const Box<T, rozmiar> &K)
  {
    for (unsigned i = 0; i < rozmiar; ++i)
      o << K.box[i] << " ";
    return o;
  }

  Box() : m_size(rozmiar)
  {
  }

  T &operator[](unsigned i) ;

  void SetAll(const T &obj);

private:
  unsigned m_size;
  T        box[rozmiar];
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
} // End of namespace

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  OOP::Box<OOP::Box<int, 1>, 10> a;

  for (int i = 0; i < 10; ++i)
    a[i][0] = i;

  cout << a << endl;

  return 0;
}
