#pragma once

#include <iostream>

#include "Point2D.h"

class Point2D
{
	private:
		double _x;
		double _y;
	public:
		friend class PointAverage;
		/**
		 * @brief Construct a new Point2D object
		 * 
		 * @param a 
		 * @param b 
		 */
		Point2D(double a = 0, double b = 0) : _x(a), _y(b) {};
		/**
		 * @brief Destroy the Point 2 D object
		 * 
		 */
		~Point2D(){}
		/**
		 * @brief Overloaded + operator, adds to _x and _y
		 * 
		 * @param a 
		 * @return Point2D& 
		 */
		 Point2D & operator+( Point2D & a) {this->_x += a._x;this->_y += a._y; return *this;};
		 
		/**
		 * @brief Overloaded = operator
		 * 
		 * @param a 
		 * @return Point2D& 
		 */
		Point2D & operator=(Point2D & a) {_x=a._x; _y=a._y; return *this;};
		/**
		 * @brief Prints coordinates od Point2D object
		 * 
		 */
		void print() {std::cout <<  "Point2D::" << "(" << _x <<", "<< _y << ")\n";};
		/**
		 * @brief overloaded ++ operator
		 * 
		 * @return Point2D& 
		 */
		Point2D & operator++(int) {_x++;_y++;return*this;}
		/**
		 * @brief overloaded -- operator
		 * 
		 * @return Point2D& 
		 */
		Point2D & operator--() {--_x;--_y;return*this;};
		/**
		 * @brief overloaded new operator
		 * 
		 * @param size 
		 * @return void* 
		 */
		void * operator new(size_t size) {
			void * p = malloc(sizeof(Point2D));
			std::cout << "Point2D:: alokowanie " << sizeof(Point2D) << std::endl;
			return p;}
		/**
		 * @brief overloaded delete operator
		 * 
		 * @param p 
		 */
		double getY() {
			return _y;
		}
		/**
		 * @brief getter of _x
		 * 
		 * @return double 
		 */
		double getX() {
			return _x;
		}
		/**
		 * @brief overloaded delete operator
		 * 
		 */

};

/**
 * @brief overloaded + operator for double and Point2D object
 * 
 * @param a 
 * @param point 
 * @return Point2D& 
 */
Point2D operator+(double a, Point2D & point);