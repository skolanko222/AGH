#include "Point2DSmartPtr.h"




Point2D & operator+(double a, Point2D & point) {point.setXY(a,a); return point;};