#include "Fraction.h"
#include <iostream>

namespace OOP {

template <typename T> void swap(T &a, T &b, unsigned iter = 1)
{
  for (unsigned i = 0; i < iter; ++i)
  {
    T tmp = T(a);
    a = b;
    b = tmp;
  }
}

/////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2> T1 max(const T1 &a, const T2 &b)
{
  return (a < b) ? b : a;
}

/////////////////////////////////////////////////////////////////////////
template <typename T> const T &max(const T &a, const T &b)
{
  return (a < b) ? b : a;
}

/////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2> T1 min(const T1 &a, const T2 &b)
{
  return (a < b) ? a : b;
}
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  int            a = 10, b = 5;
  double         c = 3.14, d = 13.13;
  OOP::Fraction aFrac(2, 5), bFrac(13, 50);

  cout << "a = " << a << ", b = " << b << endl;
  cout << "c = " << c << ", d = " << d << endl;
  cout << "aFrac = " << aFrac << ", bFrac = " << bFrac << endl;

  cout << "-----------------------------------\n\n";
  cout << "max(a, b) = " << OOP::max(a, b) << endl;
  cout << "min(a, b) = " << OOP::min(a, b) << endl;

  cout << "max(b, d) = " << OOP::max(b, d) << endl;
  cout << "min(c, a) = " << OOP::min(c, a) << endl;

  cout << "max<double, double>(b, d) = " << OOP::max<double, double>(b, d)
       << endl;
  cout << "min<double, double>(c, a) = " << OOP::min<double, double>(c, a)
       << endl;

  cout << "max(aFrac, a) = " << OOP::max(aFrac, a) << endl;

  cout << "-----------------------------------\n\n";
  cout << "a = " << a << ", b = " << b << endl;
  OOP::swap(a, b);
  cout << "a = " << a << ", b = " << b << endl;
  OOP::swap(a, b, 2);
  cout << "a = " << a << ", b = " << b << endl;

}