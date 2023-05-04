#pragma once
#include "on_heap.h"
#include "scoped.h"

template <typename T, unsigned N = sizeof(std::string)> struct obj_ho1der {
  using type = typename std::conditional<(sizeof(T) <= N),
                                         scoped<T>, on_heap<T>>::type;
};

template <typename T, unsigned N = sizeof(std::string)> 
using holder_type = typename obj_ho1der<T, N>::type;
