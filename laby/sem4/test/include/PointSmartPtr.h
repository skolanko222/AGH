#pragma once
#include <string>
#include <iostream>
#include <utility>

class Named
{
	private:
		std::string _name;

	public:
		Named(std::string n = "None") : _name(n) {};
		std::string Name() {return _name;}
		void setName(std::string n) {_name = n;}
		friend Named &operator>>(std::string n,Named &o) {o._name = n; return o;}



};

Named & operator>>(std::string str, Named &o);

class Point : public Named
{
	private:
		double _x;
		double _y;
	public:
		Point(double x=0., double y=0.,std::string n = "None") : Named(n), _x(x), _y(y) {};
		friend std::ostream & operator<<(std::ostream & n, Point o) {return n << o.Name() << " [" << o._x << ", " << o._y << "]";}
		double getX() {return _x;}
		double getY() {return _y;}
		Point operator++(int)
		{
			Point tmp = Point(_x,_y,Name());
			_x++;
			_y++;

			return tmp;
		}
		~Point(){}
};

std::ostream & operator<<(std::ostream & n, Point  o);

class PointSmartPtr
{
	private:
		Point *_ptr;
		int *_count;
		void release()
		{
			if(_count != nullptr)
			{
				if((*_count) == 1) 
				{
					delete _count;
					_count = nullptr;
					if(_ptr != nullptr)
					{
						delete _ptr;
						_ptr = nullptr;
					}						
				}				
				else 
				{
					(*_count)--;
				}
			}
		}

	public:
		PointSmartPtr(Point * p = nullptr) : _ptr(p), _count(new int) {*_count = 1;};
		PointSmartPtr &operator=(const PointSmartPtr & p)
		{
			if(this == &p)
				return *this;
			_ptr = p._ptr;
			_count = p._count;
			(*_count)++;
			return *this;
		}

		Point &operator*() {return *_ptr;}
		~PointSmartPtr()
		{
			release();
		}
		

};