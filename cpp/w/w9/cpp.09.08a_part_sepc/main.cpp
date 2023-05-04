#include "Fraction.h"
#include <cstring>
#include <iostream>
#include <typeinfo>

namespace OOP {

template <typename T> void swap(T &a, T &b)
{
  T tmp = T(a);
  a = b;
  b = tmp;
}

template <typename T> void swap(T* a, T* b)
{
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap(char a[], char b[])
{
  unsigned i;
  for (i = 0; i < ((strlen(a) < strlen(b)) ? strlen(a) : strlen(b)); ++i)
  {
    char tmp = *(a + i);
    a[i] = b[i];
    b[i] = tmp;
  }
  a[i] = 0;
  b[i] = 0;
}

template <typename T> T max(const T &a, const T &b)
{
  std::cout << "Typy: " << typeid(a).name() << ", "  << typeid(b).name() << "\n";	
  return (a < b) ? b : a;
}

template <typename T> T *max(T *a, T *b)
{
  std::cout << "Typy: " << typeid(a).name() << ", "  << typeid(b).name() << "\n";	
  return (*a < *b) ? b : a;
}

char *max(char *a, char *b)
{
  std::cout << "Typy: " << typeid(a).name() << ", "  << typeid(b).name() << "\n";	
  return (strlen(a) < strlen(b)) ? b : a;
}
}

/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  char a[] = "Ala";
  char b[] = "Olla";

  OOP::max(a, b);
  cout << "max(a, b) = " << OOP::max(a, b) << endl;

  cout << "a = " << a << ", b = " << b << endl;
  OOP::swap(a, b);
  cout << "a = " << a << ", b = " << b << endl << endl;

  int aa = 2, bb = 3;
  cout << "aa = " << aa << ", bb = " << bb << endl;
  cout << "max(aa, bb) = " << OOP::max(aa, bb) << endl;
  cout << "max(&aa, &bb) = " << *OOP::max(&aa, &bb) << endl;

  OOP::swap(aa, bb);
  cout << "aa = " << aa << ", bb = " << bb << endl;
  OOP::swap(&aa, &bb);
  cout << "aa = " << aa << ", bb = " << bb << endl;

  return 0;
}
