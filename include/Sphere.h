#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Color.h"
#include "Object.h"
#include "Ray.h"
#include <math.h>

class Sphere : public Object {
public:
    Sphere() : c(), radius(1), center(1,1,1) {}
    bool intersect(Ray&,float&);
private:
    Color c;
    float radius;
    Vec3 center;
};

#endif // __SPHERE_H__
