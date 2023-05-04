#pragma once 
#include <memory>

template <typename T, typename Cont> class stack
{
public:
  void pop()
  {
    c_.pop_back();
  }

  T &top()
  {
    return c_.back();
  }

  void push(const T& v)
  {
    c_.push_back(v);
  }

  size_t size() const {
    return c_.size();
  }

private:
  Cont c_;
};
