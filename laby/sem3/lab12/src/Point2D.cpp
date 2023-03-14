#include "Point2D.h"


Point2D operator+(double a, Point2D & point) {
	Point2D temp(a + point.getX(), point.getY());
    return temp; 
};