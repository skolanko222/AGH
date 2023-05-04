// https://en.cppreference.com/w/cpp/utility/pair/make_pair

#include <functional>
#include <iostream>
#include <utility>

int main()
{
  int n = 1;
  int a[5] = {1, 2, 3, 4, 5};

  // std::pair<int, double> d {1, 2.2};


  // build a pair from two ints
  auto p1 = std::make_pair(&n, &a[1]);
  std::cout << "The value of p1 is "
            << "(" << *p1.first << ", " << *p1.second << ")\n";

  // build a pair from a reference to int and an array (decayed to pointer)
  auto p2 = std::make_pair(std::ref(n), a);
  n = 7;
  std::cout << "The value of p2 is "
            << "(" << p2.first << ", " << *(p2.second + 2) << ")\n";

  // C++17 Class template argument deduction (CTAD)
  // https://en.cppreference.com/w/cpp/language/class_template_argument_deduction
  std::pair p3 = {1, 3};
  std::cout << "The value of p3 is "
            << "(" << p3.first << ", " << p3.second << ")\n";
}