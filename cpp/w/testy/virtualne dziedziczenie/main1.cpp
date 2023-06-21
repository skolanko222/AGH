#include <iostream>
class A1
{
	public:
		A1() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
		~A1() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
		int a = 0;
};
class A2
{
	public:
		A2() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
		~A2() { std::cout << __PRETTY_FUNCTION__  << '\n'; }	
		int a = 0;
};

class B :virtual public A2
{
	public:
		B() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
		~B() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
};

class C : virtual public A1
{
	public:
		C() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
		~C() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
};


class D : public C,  virtual public B
{
	public:
		D() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
		~D() { std::cout << __PRETTY_FUNCTION__  << '\n'; }
};

int main()
{
	D d;
}
