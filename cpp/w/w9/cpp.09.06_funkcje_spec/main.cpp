#include "Fraction.h"
#include <cstring>
#include <iostream>

namespace OOP {

template <typename T> 
  void swap(T &a, T &b)
{
  T tmp = T(a);
  a = b;
  b = tmp;
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

/////////////////////////////////////////////////////////////////////////
template <typename T1, typename T2> T1 
max(const T1 &a, const T2 &b)
{
  return (a < b) ? b : a;
}

char *max(char *a, char *b)
{
  return (strlen(a) < strlen(b)) ? b : a;
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

  OOP::swap(aa, bb);
  cout << "aa = " << aa << ", bb = " << bb << endl;

  return 0;
}
