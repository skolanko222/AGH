#pragma once
#include "Map2.h"

namespace MTH{
    class Point{
        private:
            double _x;
            double _y;
        public:
            Point(double x, double y) : _x(x), _y(y) {};
            double get_x()const{
                return _x;
            }
            double get_y()const{
                return _y;
            }
			Point& operator=(const Point &p);
			Point(const MP::Point& x) {};	
	};
    void Print(const Point &);
    
}