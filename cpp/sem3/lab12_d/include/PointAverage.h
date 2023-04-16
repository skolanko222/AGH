#pragma once

#include <iostream>
#include <functional>
#include <vector>

#include "Point2DSmartPtr.h"

class PointAverage
{

	private:
		std::vector<double> x_arr;
		std::vector<double> y_arr;

	public:
		void operator()(Point2D & p) {x_arr.push_back(p._x);y_arr.push_back(p._y);};
		void print() {};
		void reset() {};
	
	
};