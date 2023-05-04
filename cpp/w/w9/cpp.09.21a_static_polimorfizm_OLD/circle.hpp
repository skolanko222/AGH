#ifndef CIRCLE_HPP
#define CIRCLE_HPP

// header file for I/O
#include <iostream>

// header file of the base class
#include "geoobj.hpp"

namespace Geo {

/* class Circle
 * - derived from GeoObj
 * - a circle consists of:
 *     - a center point (reference point, inherited)
 *     - a radius (new)
 */
class Circle : public GeoObj {
  protected:
    unsigned radius;    // radius

  public:
    // constructor for center point and radius
    Circle(const Coord& m, unsigned r)
         : GeoObj(m), radius(r) {
    }

    // draw geometric object (now implemented)
    virtual void draw() const;

    // virtual destructor
    virtual ~Circle() {
    }
};

/* drawing
 * - defined inline
 */
inline void Circle::draw() const
{
    std::cout << "Circle around center point " << refpoint
              << " with radius " << radius << std::endl;
}

}  // namespace Geo

#endif // CIRCLE_HPP