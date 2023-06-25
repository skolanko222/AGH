#include <iostream>
#include <vector>
#include <iostream>
#include <array>

struct A { int a;};
struct B {virtual void f() {} int a;};

template<typename T>
void memcopy(T *src, T *dst, unsigned size)
{
	std::cout << "Copying" << (std::is_pod<T>::value == 1 ? "POD type\n" : "non-POD type.\n");
	
}

template <typename T>
void test() {
	T src[10] = {}, dst[10];
	std::cout << typeid(T).name() << " is_pod = " << std::is_pod<T>::value << ", ";
	memcopy(src, dst, sizeof(src)/sizeof(T));
}


int main() {

	test<A>();
	test<B>();
	test<std::array<A,10>>();
	test<std::vector<A>>();

    return 0;
}
/*
A is_pod = 1, Copying POD type.
B is_pod = 0, Copying non-POD type.
std::array<A,10> is_pod = 1, Copying POD type.
std::vector<A> is_pod = 0, Copying non-POD type.
*/