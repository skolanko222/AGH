#pragma once
#include <string>
#include "Named.h"

class Point : public Named
{  
    private:
        double _x;
        double _y;
    public:
        Point(double x=0.0, double y=0.0, std::string str="None"): _x(x), _y(y) 
        {
            this->nazwaSet(str);
        }
        ~Point() 
        {
            
        }
        
        double xGet() const
        {
            return _x;
        }
        double yGet() const
        {
            return _y;
        }
        
        Point& operator++()
        {
            this->_x+=1;
            this->_y+=1;
            return *this;
        }
        Point operator++(int)
        {
            Point temp = *this;
            operator++();
            return temp;
        }
};

std::ostream& operator<<(std::ostream& out, const Point& a);
void operator>> (std::string str, Point& a);