#include <iostream>

struct SomeStruct
{
  auto FuncName(int x, int y) -> int; // c++11
  // auto FuncName(int x, int y);        // c++14
};

auto SomeStruct::FuncName(int x, int y) -> int // c++11
// auto SomeStruct::FuncName(int x, int y)        // c++14
{
  return x + y;
}


// auto Func() -> double;
auto Func();

// auto Func() -> double
auto Func()
{
  return 2.123;
}

int main()
{ 
  SomeStruct s;

  std::cout << s.FuncName(5, 7) << ", " << Func() << "\n";
}