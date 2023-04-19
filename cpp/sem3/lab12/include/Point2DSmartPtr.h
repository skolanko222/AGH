#pragma once
#include <iostream>

#include "Point2D.h" //class Point2D;

class Point2DSmartPtr
{
	private:
		Point2D * _pointer;
	
	public:
		/**
		 * @brief Construct a new Point 2 D Smart Ptr object
		 * 
		 * @param point 
		 */
		Point2DSmartPtr(Point2D & point) : _pointer(&point) {}
		/**
		 * @brief Construct a new Point 2 D Smart Ptr object
		 * 
		 * @param point 
		 */
		Point2DSmartPtr(Point2D * point) : _pointer(point) {} 
		/**
		 * @brief overloaded -> operator
		 * 
		 * @return Point2D* 
		 */
		Point2D * operator->() {return _pointer;}
		~Point2DSmartPtr() {std::cout << "Point2D:: zwalnianie wskaznika" << std::endl;}

};