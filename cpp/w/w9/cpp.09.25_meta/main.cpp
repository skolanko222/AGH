#include <iostream>
#include <string>
#include "obj_holder.h"

struct big {
  int t[8];
  virtual ~big() = default;
};

int main()
{
  holder_type<int> a;
  holder_type<int, 2> aa;
  holder_type<big> b;
  holder_type<big, 64> bb;

  *aa = *a = 5;
}
