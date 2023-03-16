#include <cassert>
#include <iostream>

struct C {
  int x = 1, y = 2;
};

int main()
{
  C    c;
  int *px = &c.x;    // value of px is "pointer to c.x"
  int *pxe = px + 1; // value of pxe is "pointer past the end of c.x"
  int *py = &c.y;    // value of py is "pointer to c.y"

  int C::*ptr = &C::x;
  (c.*ptr) = 6;

  // problem
  assert(pxe == py); // == tests if two pointers represent the same address
                     // may or may not fire
  // problem
  *pxe = 4; // undefined behavior even if the assertion does not fire

  // std::cout << c.x << " " << c.y << "\n";
}
