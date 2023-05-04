#ifndef GEOGROUP_HPP
#define GEOGROUP_HPP

// include header file of the base class
#include "geoobj.hpp"

// header file for the internal management of the elements
#include <vector>

namespace Geo {

/* class GeoGroup
 * - derived from GeoObj
 * - a GeoGroup consists of:
 *     - a reference point (inherited)
 *     - a collection of geometric elements (new)
 */
class GeoGroup : public GeoObj {
  protected:
    std::vector<GeoObj*> elems;    // collection of pointers to GeoObjs

  public:
    // constructor with optional reference point
    GeoGroup(const Coord& p = Coord(0,0)) : GeoObj(p) {
    }

    // output (now also implemented)
    virtual void draw() const;

    // insert element
    virtual void add(GeoObj&);

    // remove element
    virtual bool remove(GeoObj&);

    // virtual destructor
    virtual ~GeoGroup() {
    }
};

}  // namespace Geo

#endif  // GEOGROUP_HPP