#pragma once

#include <string>
#include <iostream>
#include "Named.h"

class Point : public Named
{
	private:
		double _x;
		double _y;
	public:
		Point(double a = 0, double b = 0, std::string n = "None") : _x(a), _y(b) 
		{
			setName(n);
		}
		double getX() const{return _x;}
		double getY() const{return _y;}
		Point& operator++()
        {
            this->_x+=1;
            this->_y+=1;
            return *this;
        }
        Point operator++(int)
        {
            Point temp = *this;
            operator++();
            return temp;
        }


};

std::ostream &operator<<(std::ostream &o, Point obj);
