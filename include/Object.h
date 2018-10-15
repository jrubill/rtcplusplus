#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Vec3.h"
#include "Color.h"
#include "Ray.h"
class Object {
public:
    virtual bool intersect(Ray&, float&) = 0;
    virtual Color getColor() = 0;
    virtual Vec3 getNormal(Vec3&) = 0;
    virtual Vec3 getCenter() = 0;
};
#endif // __OBJECT_H__
