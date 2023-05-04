#include "Fraction.h"
#include <cstring>
#include <iostream>
#include <typeinfo>

namespace OOP {

// template <typename T> T max(const T &a, const T &b)
// {
//   return (a < b) ? b : a;
// }

template <typename T1, typename T2> 
auto max(const T1& a, const T2& b) //-> decltype((a < b) ? b : a) // C++11
{
  std::cout << "Typy: " << typeid(a).name() << ", "  << typeid(b).name() << "\n";
  return (a < b) ? b : a;
}


template <typename T1, typename T2> 
auto max(T1* a, T2* b) // C++14
{
  std::cout << "Typy: " << typeid(a).name() << ", "  << typeid(b).name() << "\n";
  return (*a < *b) ? *b : *a;
}

char* max(char *a, char *b)
{
  return (strlen(a) < strlen(b)) ? b : a;
}
}

/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  int aa = 2;
  OOP::Fraction bb = 3;

  cout << "aa = " << aa << ", bb = " << bb << endl;
  cout << "max(aa,   aa) = " << OOP::max(aa, aa) << endl;
  cout << "max(aa,   bb) = " << OOP::max(aa, bb) << endl;
  // cout << "max(&aa, &bb) = " << OOP::max(&aa, &bb) << endl;
}
