// https://en.cppreference.com/w/cpp/iterator/advance
// https://en.cppreference.com/w/cpp/iterator/next

#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> v{0, 1, 4, 6, 7};

  auto vi = v.begin();

  std::advance(vi, 4);
  std::advance(vi, -2);

  std::cout << "Value of iterator vi: "<< *vi << '\n';
  std::cout << "Distance from begining: "<< std::distance(v.begin(), vi) << '\n';

  // Although the expression ++c.begin() often compiles, it is not guaranteed to
  // do so: c.begin() is an rvalue expression. In particular, when iterators are
  // implemented as pointers, ++c.begin() does not compile, while
  // std::next(c.begin()) does.
  for (auto nx = std::next(v.begin()); nx != std::prev(v.end()); ++nx)
    std::cout << *nx << " ";
}
