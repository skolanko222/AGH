#include "Named.h"
#include "Point.h"
#include <string>

class PointSmartPtr
{
	private:
		Point * _ptr;
		
	public:
		static int _count;
		PointSmartPtr(Point * p) :  _ptr(p) {_count++;}
		~PointSmartPtr() {_count--; delete _ptr; _ptr = nullptr;}
		
		PointSmartPtr &operator=(PointSmartPtr &a)
		{
			if(this == &a)
				return a;
			Point *temp = new Point(a._ptr->getX(), a._ptr->getY(), a._ptr->Name());
			_ptr =  temp;

		}
		PointSmartPtr(PointSmartPtr & p) { *this = p; _count++;}
		Point &operator*() {return *_ptr;}
};
