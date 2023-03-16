#include <iostream>

struct A {
  int sub(int a, int b) const
  {
    return a - b;
  }
  int div(int a, int b) const
  {
    return a / b;
  }
};

int fun(int m, int n, A *obj, int (A::*mfp)(int, int) const)
{
  return (obj->*mfp)(m, n);
}

int fun(int m, int n, const A &obj, int (A::*mfp)(int, int) const)
{
  return (obj.*mfp)(m, n);
}

int main()
{
  A obj;
  std::cout << "div() = " << fun(12, 4, &obj, &A::div) << std::endl;
  std::cout << "sub() = " << fun(12, 4, &obj, &A::sub) << std::endl;
  
  std::cout << "div() = " << fun(6, 2, obj, &A::div) << std::endl;
  std::cout << "sub() = " << fun(6, 2, obj, &A::sub) << std::endl;
}
