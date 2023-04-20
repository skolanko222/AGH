#include "MapPoint.h"
#include <iostream>

void MTH::Print(const Point &p){
    std::cout << "[MTH::Point] X=" << p.get_x() << " Y=" << p.get_y() << std::endl;
}

void MP::Print(const MP::Point &p){
    std::cout << "[MP::Point] " << p.get_label() << ": Lattitude=" << p.get_lattitude() << " Longitute=" << p.get_longitude() << std::endl; 
}

MP::Point::Point(string s, MTH::Point &p) : Point(s, p.get_x(), p.get_y()) {};

MTH::Point& MTH::Point::operator=(const MTH::Point &p){
    if(&p == this){
        std::cout << "[MTH::Warning] Discarding self-assignment" << std::endl;
        return *this;
    }
    _x = p._x;
    _y = p._y;

    return *this;
}