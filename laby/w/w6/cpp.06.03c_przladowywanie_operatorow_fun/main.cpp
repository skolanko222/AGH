#include <iostream>
#include <functional>
#include <vector>

struct F1 {
    void operator()(int n) { 
    	std::cout << __PRETTY_FUNCTION__ << ": " << n << std::endl;
    }
};

struct F2 {
    void operator()(int n) { 
    	std::cout << __PRETTY_FUNCTION__ << ": " << n << std::endl;
    }
};

struct F3 {
    void operator()(int n) { 
    	std::cout << __PRETTY_FUNCTION__ << ": " << n << std::endl;
    }
};

struct F4 {
    void operator()() { 
    	std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

struct F5 {
    void operator()() { 
    	std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

/////////////////////////////////////////////////////////
int main() {

	std::vector<std::function<void(int)>> vec;
	std::vector<std::function<void()>> vec2;

	vec.emplace_back(F1());
	vec.emplace_back(F2());
	vec.emplace_back(F3());

	int i = 0;
	for(auto& el : vec) {
		el(++i);
		vec2.emplace_back(std::bind(el, i));
	}

	vec2.push_back(F4());
	vec2.emplace_back(F5());
	for(auto& el : vec2)
		el();

}
