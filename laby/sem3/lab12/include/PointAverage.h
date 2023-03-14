#pragma once

#include <iostream>

#include "Point2D.h"

class PointAverage
{
    private:
        double _x_sum;
        double _y_sum;
        int count = 0;

    public:
		/**
		 * @brief overloaded operator ()
		 * 
		 * @param o 
		 */
        void operator()(Point2D & o) {
            if ( (_x_sum == 0) && (_y_sum == 0) ) {
                _x_sum=o._x;
                _y_sum=o._y;
                count++;
            }
            else {
                count++;
                _x_sum += o._x;
                _y_sum += o._y;
                _x_sum /= count;
                _y_sum /= count;
            }
        };
        /**
         * @brief prints out average point
         * 
         */
        void print() {
			std::cout << "Average Point::" << _x_sum << " " << _y_sum << std::endl;
		};
        /**
         * @brief resets variables
         * 
         */
		void reset() {
			_x_sum = 0;
			_y_sum = 0;
			count = 0;
		};
        

};