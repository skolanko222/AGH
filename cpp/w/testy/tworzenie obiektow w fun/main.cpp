#include <iostream>

class A
{
	private:
		int x;
	public:
		A(int x ) : x(x) {std::cout << __PRETTY_FUNCTION__ << " addres: " << this << std::endl;}
		A(const A & o)  : x(o.x) {std::cout << "copy " << "addres: " << this << std::endl;}

		A(A && o) : x(std::move(o.x)) {std::cout << "move " << "addres: " << this << std::endl;}

		~A() {std::cout << __PRETTY_FUNCTION__ << " addres: " << this << std::endl;}

};
A ret_copy(A a)
{
	A temp = A(a);
	return temp;
	// kopia bo lokalna zmienna
}
A ret_move(A a)
{
	return a;
	// kopia bo lokalna zmienna
}

int main(void)
{
	A(5);
	std::cout << "1" << std::endl;
	A a = ret_copy(A(2));
	std::cout << "2" << std::endl;
	A b = ret_move(A(ret_move(A(2))));
	std::cout << "3" << std::endl;
	A c = A{A(A(ret_move(A(2))))}; // copy elision
	// use move constructor
	// A c = std::move(a);

	


	return 0;

}