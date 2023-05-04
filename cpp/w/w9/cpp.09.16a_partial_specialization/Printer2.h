#pragma once

#include <iostream>
#include <memory>


struct Printer2 {

  explicit Printer2(const std::string &prefix = "",
                    const std::string &suffix = "",
                    const std::string &new_line = "\n")
      : _prefix(prefix), _suffix(suffix), _new_line(new_line)
  {
  }

  template <typename T>
  std::ostream &print(std::ostream &o, const T &elem) const
  {
    return o << _prefix << elem << _suffix << " " << __PRETTY_FUNCTION__ << _new_line;
  }

  template <typename T>
  std::ostream &print(std::ostream &o, T *const elem) const
  {
    return o << _prefix << *elem << _suffix << " " << __PRETTY_FUNCTION__ << _new_line;
  }

  template <typename T>
  std::ostream &print(std::ostream &o, const std::unique_ptr<T>& elem) const
  {
    return o << _prefix << *elem << _suffix << " " << __PRETTY_FUNCTION__ << _new_line;
  }

private:
  std::string _prefix, _suffix, _new_line;
};
