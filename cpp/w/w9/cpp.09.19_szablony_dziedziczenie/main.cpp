#include "Fraction.h"
#include "OOPFunTemplates.h"
#include <iostream>

namespace OOP {

class CFun
{
public:
  long ComplexFun(long x);
};

long CFun::ComplexFun(long x)
{
  for (long i = x - 1; i > 1; --i)
  {
    if (x % i == 0)
      return i;
  }
  return 1;
}
/////////////////////////////////////////////////////////////////////////
template <typename T> class Box : public CFun
{
public:
  Box(unsigned size = 1)
  {
    box = new T[size];
    this->size = size;
  }

  ~Box()
  {
    delete[] box;
  }

  long Podziel()
  {
    return ComplexFun(size);
  }

  T *      box;
  unsigned size;
};
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  OOP::Box<int>   BoxInt(25);
  OOP::Box<float> BoxFloat(33);
  OOP::Box<char>  BoxChar(73);

  cout << "BoxInt.Podziel() = " << BoxInt.Podziel() << endl;
  cout << "BoxFloat.Podziel() = " << BoxFloat.Podziel() << endl;
  cout << "BoxChar.Podziel() = " << BoxChar.Podziel() << endl;

  return 0;
}
