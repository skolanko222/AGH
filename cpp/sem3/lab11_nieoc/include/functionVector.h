#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <functional>

class FunctionVector
{
	public:
		std::vector<std::function<double(double)>> _vec;
		std::vector<double> _results;
	public:
		FunctionVector(std::function<double(double)> fun = nullptr) {_vec.emplace_back(fun);}
		void insert(std::function<double(double)> fun) {_vec.emplace_back(fun);}
		void operator+=(std::function<double(double)> fun) {insert(fun);}
		double calc(double x)
		{
			double temp_x = x;
			for(auto it = _vec.rbegin(); it != _vec.rend(); ++it)
			{
				//temp_x = it(temp_x);
				//_results.emplace_back(temp_x);
			}
			return temp_x;
		}
};