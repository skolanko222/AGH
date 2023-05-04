#pragma once
#include <iostream>

template <typename T> struct on_heap {

  on_heap() : p(new T)
  {
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }
  ~on_heap()
  {
    delete p;
  }

  T &operator*()
  {
    return *p;
  }
  T *operator->()
  {
    return p;
  }
  on_heap(const on_heap &) = delete;
  on_heap &operator=(const on_heap &) = delete;

private:
  T *p;
};
