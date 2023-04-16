#pragma once

#include <iostream>
#include "PointAverage.h"

class Point2D
{
	private:
		double _x;
		double _y;
	public:
		friend class PointAverage;
		Point2D(double a = 0, double b = 0) : _x(a), _y(b) {};
		Point2D & operator+(Point2D & a) {_x += a._x; _y += a._y;return *this;};
		Point2D & operator=(Point2D & a) {_x = a._x; _y = a._y; return *this;};
		void print() {std::cout <<  "Point2D::" << "(" << _x <<", "<< _y << ")\n";};
		Point2D & operator++(int) {_x++;_y++;return *this;}
		Point2D & operator--() {--_x;--_y;return *this;};
		void * operator new(size_t size) {
			void * p = malloc(sizeof(Point2D));
			std::cout << "Point2D:: alokowanie " << sizeof(Point2D) << std::endl;
			return p;}
		void operator delete(void * p) {free(p);}
		void setXY(double a,double b) {_x+=a; _y+=b;}

};

Point2D & operator+(double a, Point2D & point);

class Point2DSmartPtr
{
	private:
		Point2D * _pointer;
	
	public:
		Point2DSmartPtr(Point2D & point) : _pointer(&point) {}
		Point2DSmartPtr(Point2D * point) : _pointer(point) {} //dla new
		Point2D * operator->() {return _pointer;}

};