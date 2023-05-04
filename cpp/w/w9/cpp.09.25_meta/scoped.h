#pragma once
#include <iostream>

template <typename T> struct scoped {

  scoped()
  {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }

  T &operator*()
  {
    return x;
  }
  T *operator->()
  {
    return &x;
  }
  scoped(const scoped &) = delete;
  scoped &operator=(const scoped &) = delete;

private:
  T x;
};
