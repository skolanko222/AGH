#include <iostream>
#include <algorithm>
#include <functional>

struct Sum
{
    Sum(int a = 0) : sum(a) { }

    operator int(){
    	return sum;
    }

    void operator()(int n) { 
    	sum += n; 
    }
private:
    int sum;
};

/////////////////////////////////////////////////////////
int main() {

	Sum s{10};
	std::cout << "Suma = " << s << std::endl;

	for (int i = 0; i < 5; ++i)	{
		s(i);
		std::cout << "Suma = " << s << std::endl;
	}

	{
		std::function<void(int)> f_s = s;
		f_s(100);
		std::cout << "Suma f_s = " << s << std::endl;
	}
	{
		std::function<void(int)> f_s = std::ref(s);
		f_s(100);
		std::cout << "Suma std::ref f_s = " << s << std::endl;
	}
	

}
