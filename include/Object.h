#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Vec3.h"
#include "Color.h"
#include "Ray.h"
class Object {
public:
    virtual bool intersect(Ray&, float&) const = 0;
    virtual Color getColor() const = 0;
    virtual Vec3 getNormal(Vec3&) const = 0;
    virtual Vec3 getCenter() const = 0;
    virtual ~Object() {}
};
#endif // __OBJECT_H__
