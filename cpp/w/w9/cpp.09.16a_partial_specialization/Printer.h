#pragma once

#include <iostream>

template <typename T> struct Printer {

	using value_typu = T;

  explicit Printer(const T &elem, const std::string &prefix = "",
                   const std::string &suffix = "",
                   const std::string &new_line = "\n")
      : _elem(elem), _prefix(prefix), _suffix(suffix), _new_line(new_line)
  {
  }

  std::ostream &print(std::ostream &o) const
  {
    return o << _prefix << _elem << _suffix << _new_line;
  }

private:
  T           _elem;
  std::string _prefix, _suffix, _new_line;
};

/////////////////////////////////////////////////////////////////////////
template <typename T> struct Printer<T *> {

  explicit Printer(T *const elem, const std::string &prefix = "",
                   const std::string &suffix = "",
                   const std::string &new_line = "\n")
      : _elem(elem), _prefix(prefix), _suffix(suffix), _new_line(new_line)
  {
  }

  ~Printer()
  {
    delete _elem;
  }

  std::ostream &print(std::ostream &o) const
  {
    return o << _prefix << *_elem << _suffix << _new_line;
  }

private:
  T *const    _elem;
  std::string _prefix, _suffix, _new_line;
};
