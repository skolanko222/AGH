#include <iostream>
#include <string>
#include <utility>

struct A {
  friend int main();

  A() : s("test"), k(-1) {
    std::cout << "default const\n";
  }
  A(const A &o) : s(o.s), k(o.k) {
    std::cout << "move failed, coping!\n";
  }
  A(A &&o)
      : s(std::move(o.s)),       // explicit move of a member of class type
        k(std::exchange(o.k, 0)) // explicit move of a member of non-class type
  {
    std::cout << "moving!\n";
  }

private:
  std::string s;
  int         k;

};

A f(A a) {
  return a;
}

int main() {
  A a1 = f(A()); // return by value 
  std::cout << "Before move, a1.s = " << a1.s << " a1.k = " << a1.k
            << '\n';
  A a2 = std::move(a1); // move-constructs from xvalue
  std::cout << "After move, a1.s = " << a1.s << " a1.k = " << a1.k
            << '\n';

}
