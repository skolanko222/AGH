#include "Fraction.h"
#include <iostream>

namespace OOP {

template <typename T> T max(T a, T b)
{
  return (a < b) ? b : a;
}

template <typename T> T min(T a, T b)
{
  return (a < b) ? a : b;
}
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  cout << "max(2.3, 3.3) = " << OOP::max(2.3, 3.3) << endl;
  cout << "min(2.3, 3.3) = " << OOP::min(2.3, 3.3) << endl;

  cout << "max(2.3, 3.3) = " << OOP::max<long>(2.3, 3.3) << endl;
  cout << "min(2.3, 3.3) = " << OOP::min<long>(2.3, 3.3) << endl;

  cout << "max('a', 'b') = " << OOP::max<unsigned short>('a', 'b') << endl;
  cout << "min('a', 'b') = " << OOP::min<unsigned short>('a', 'b') << endl;

 }