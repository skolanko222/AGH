#include <cstdlib>
#include <iostream>

// Standardowy szablon klasy array
template <typename T, size_t N> struct array {

  array()
  {
    for (auto &i : *this)
    {
      i = T();
    }
  }

  T &operator[](size_t i)
  {
    return _t[i];
  }

  T *begin()
  {
    return &_t[0];
  }

  T *end()
  {
    return &_t[0] + N;
  }

private:
  T _t[N];
};

// Specjalizowana wesja szablon klasy array dla typu void*
template <size_t N> struct array<void *, N> {

  array()
  {
    // std::cout << __PRETTY_FUNCTION__ << "\n";
    for (auto &i : *this)
    {
      i = nullptr;
    }
  }

  void *&operator[](size_t i)
  {
    return _t[i];
  }

  void **begin()
  {
    return &_t[0];
  }

  void **end()
  {
    return &_t[0] + N;
  }

protected:
  void *_t[N];
};


// Część Specjalizowana wesja szablon klasy array dla typów T* wykorzystująca
// wersję std
template <typename T, size_t N>
struct array<T *, N> : private array<void *, N>{

  typedef array<void *, N> Base;
  // array()
  // {
  //   std::cout << __PRETTY_FUNCTION__ << "\n";
  // }

  T *&operator[](size_t i)
  {
    return reinterpret_cast<T *>(this->_t[i]);
  }

  T **begin()
  {
    return reinterpret_cast<T **>(&array<void *, N>::_t[0]);
  }

  T **end()
  {
    return reinterpret_cast<T **>((&Base::_t[0]) + N);
  }
};

int main(int argc, char **argv)
{
  array<int *, 100> a;

  int val = 10;
  for (auto &i : a)
    i = new int(++val);

  for (const auto &i : a)
    std::cout << *i << ", ";

  for (auto &i : a)
    delete i;

  array<double, 250> b;

  for (auto &i : b)
    i = ++val;

  for (const auto &i : b)
    std::cout << "[" << i << "], ";
}
