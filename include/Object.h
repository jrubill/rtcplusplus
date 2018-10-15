#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Vec3.h"
#include "Color.h"

class Object {
public:
   // virtual bool intersect(Ray&, float&) = 0;
    virtual const Color &getColor() = 0;
    virtual Vec3 &getNormal() = 0;
    virtual Vec3 &getCenter() = 0;
};
#endif // __OBJECT_H__