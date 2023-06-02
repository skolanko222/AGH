#include <iostream>

class Point
{
	private:
		int _x;
		int _y;
		// int &x;
	public:
		Point(int x, int y) : _x(x), _y(y) {std::cout << "Point(int, int)" << std::endl;}
		Point & operator+(const Point &x)
		{
			std::cout << "Point & operator+(const Point &) " << _x << " " << _y << std::endl;
			_x += x._x;
			_y += x._y;
			return *this;
		}
		Point & operator!()
		{
			std::cout << "Point & operator!() " << _x << " " << _y << std::endl;
			_x = -_x;
			_y = -_y;
			return *this;
		}
		void print()
		{
			std::cout << "Point::print() " << _x << " " << _y << std::endl;
		}



};



int main(void)
{
	Point a = {1, 2};
	Point b = {3, 4};
	Point c = {5, 6};

	
	// Point d = a + b + c; //  a -> b - > c
	// std::cout << "d = a + b + c" << std::endl;
	// a.print();
	// b.print();
	// c.print();
	// d.print();
	// d = a + !b + c; // pierwsze !b, potem a -> b - > c
	// std::cout << "d = a + !b + c" << std::endl;
	// a.print();
	// b.print();
	// c.print();
	// d.print();
	
	Point && csda = std::move(a);

	return 0;
}