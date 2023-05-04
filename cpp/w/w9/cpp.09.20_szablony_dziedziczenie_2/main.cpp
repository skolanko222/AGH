#include "Fraction.h"
#include "OOPFunTemplates.h"
#include <iostream>
#include <string>

namespace OOP {

template <typename T> class Box
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

  T *      box;
  unsigned size;
};
/////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2> class BetterBox : public Box<T2>
{
public:
  BetterBox(T1 obj, unsigned size = 1) : Box<T2>(size), Extra(obj)
  {
  }
  T1 Extra;
};
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &o, BetterBox<T1, T2> &obj)
{
  o << obj.Extra << ": ";
  for (unsigned i = 0; i < obj.size; ++i)
    o << obj.box[i] << ", ";
  return o;
}
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;
  OOP::BetterBox<string, double> BBD(string("BetterBox"), 10);

  for (unsigned i = 0; i < 10; ++i)
    BBD.box[i] = i * 3.14159;

  cout << BBD << endl;
  return 0;
}
