#include <iostream>

class A
{
	private:
		int x;
	public:
		A(int x ) : x(x) {std::cout << __PRETTY_FUNCTION__ << std::endl;}
		A(const A & o)  : x(o.x) {std::cout << "copy" << std::endl;}

		A(A && o) : x(std::move(o.x)) {std::cout << "move" << std::endl;}

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
	A a = ret_copy(A(2));
	A b = ret_move(A(2));
	// use move constructor
	// A c = std::move(a);

	


	return 0;

}