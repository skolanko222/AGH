#include <iostream>
#include <vector>

/////////////////////////////////////////////////////////

void* operator new(std::size_t sz) {
    std::cout << "global op new called, size = " << sz << std::endl;
    return std::malloc(sz);
}
void operator delete(void* ptr) noexcept //c++11
{
    std::cout << "global op delete called" << std::endl;
    std::free(ptr);
}

/////////////////////////////////////////////////////////
int main()
{
	int* p2 = new int[10];
	delete [] p2;

	std::vector<char> v(1213);
}
