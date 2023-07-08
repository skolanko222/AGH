// Generic __cpp_lambdas
// https://riptutorial.com/cplusplus/example/1969/generic-lambdas

#include <iostream>
struct 
{
    template<typename T>
	    void operator()(T x) const {
	        std::cout << x << '\n';
	    }
	} someInstance;

int main() {
	auto foo = [](auto x) { std::cout << x << '\n'; };

	someInstance(10);
	foo(10.1234);
	foo("hello world");
}

