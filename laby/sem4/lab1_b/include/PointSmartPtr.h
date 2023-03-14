#pragma once
#include <string>
#include "Point.h"
#include "Named.h"

class PointSmartPtr
{
    private:
        Point * _pp;
        static int * _pi;
    public:
        PointSmartPtr(Point *a): _pp(a) 
        {
            (*_pi)++;
            //std::cout << *_pi << std::endl;
        }
        PointSmartPtr(const PointSmartPtr & a)
        {
            (*_pi)++;
            //std::cout << *_pi << std::endl;
            Point *temp = new Point(a._pp->xGet(), a._pp->yGet(), a._pp->Name());
            this->_pp = temp;
        }
        ~PointSmartPtr()
        {
            (*_pi)--;
            //std::cout << *_pi << std::endl;
            delete _pp;
            if(_pi==0)
                release();
        }

        Point& operator*()
        {
            return *_pp;
        }
        PointSmartPtr& operator=(PointSmartPtr& a)
        {
            Point *temp = new Point(a._pp->xGet(), a._pp->yGet(), a._pp->Name());
            this->_pp = temp;
            return *this;
        }

        void release()
        {
            delete _pi;
        }

};