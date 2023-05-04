#include <iostream>

struct true_type{};
struct false_type{};

template <typename T>
struct is_ptr
{
	typedef false_type type;
	static const bool value = false;
};

template <typename T>
struct is_ptr<T*>
{
	typedef true_type type;
	static const bool value = true;
};


template <typename T>
struct is_const
{
	typedef false_type type;
	static const bool value = false;
};

template <typename T>
struct is_const<const T>
{
	typedef true_type type;
	static const bool value = true;
};

template <typename T>
struct is_const<const T*>
{
	typedef true_type type;
	static const bool value = true;
};

template <typename T>
struct is_const<const T&>

{
	typedef true_type type;
	static const bool value = true;
};

template <bool v>
struct static_assert_test;

template<>
struct static_assert_test<true>
{
	enum {value = 1};
};

#define STATIC_ASSERT(T) static_assert_test<T>::value



template <unsigned n>
struct fibb
{
  static const unsigned long value = fibb<n-1>::value + fibb<n-2>::value;
};

template<>
struct fibb<1>
{
  static const unsigned long value = 1;
};

template<>
struct fibb<0>
{
  static const unsigned long value = 0;
};


struct A
{};

int main()
{
  std::cout
    << is_ptr<A>::value << "\n"
    << is_ptr<A*>::value << "\n"
    << is_ptr<const A*>::value << "\n"
    << is_const<const A*>::value << "\n"
    << is_const<A>::value << "\n" 	  	 
    << "fibb<20>::value = " << fibb<20>::value 
    << std::endl;
	
  int test[fibb<20>::value];
  std::cout << sizeof(test) << "\n";

  STATIC_ASSERT(is_ptr<A*>::value);
  
  static_assert(is_ptr<A*>::value, "Requires ptr");  //c++11
  
}
