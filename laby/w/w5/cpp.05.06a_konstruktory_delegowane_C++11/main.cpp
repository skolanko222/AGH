#include <iostream>

class Foo {
  char _x = 'b';
  int  _y = 1;

public:
  Foo(char x, int y) : _x{x}, _y{y} {}
  Foo(int y = 0) : Foo{'a', y} {}    // Foo(int) delegates to Foo(char,int)

  void print()   {
    std::cout << _x << ": " << _y << "\n";
  }
};

/////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
  { Foo f; f.print(); }
  { Foo f = {}; f.print(); }
  { Foo f = {'x'}; f.print(); }
  { Foo f = {'x', 13}; f.print(); }
}
