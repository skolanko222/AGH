#include <iostream>

namespace OOP 
{
	template<typename T> static T max(T a, T b)
	{
		std::cout << "Szablon file 1\n";
		return (a < b) ? b : a;
	}
}

void fun1(int a, int b)
{
	int (*ptr)(int, int);
	ptr = OOP::max<int>;

	std::cout << "fun1: " << reinterpret_cast<size_t>(ptr) << " " << ptr(a, b) << std::endl;
}