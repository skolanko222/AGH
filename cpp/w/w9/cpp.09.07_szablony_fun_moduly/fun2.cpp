#include <iostream>

namespace OOP 
{
	template<typename T> T max(T a, T b)
	{
		std::cout << "Szablon file 2\n";
		return (a < b) ? b : a;
	}
}

void fun2(int a, int b)
{
	int (*ptr)(int, int);
	ptr = OOP::max<int>;

	std::cout << "fun2: " << reinterpret_cast<size_t>(ptr) << " " << ptr(a, b) << std::endl;
}