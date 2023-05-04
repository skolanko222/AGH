#pragma once 
#include <memory>
#include <deque>

namespace tt{
template <typename T = int, template <typename ElType, typename AllocType> class Cont = std::deque> class stack
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
  Cont<T, std::allocator<T>> c_;
};

}