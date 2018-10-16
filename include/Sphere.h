#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Color.h"
#include "Object.h"
#include "Ray.h"
#include <math.h>
class Sphere : public Object {
public:
    Sphere() : radius(1), center(1,1,1), color() {}
    Sphere(Vec3 c, float r) : radius(r), center(c), color(0,0,150) {}

    bool intersect(Ray&,float&) const;

    Vec3 getCenter() const;
    Vec3 getNormal(Vec3 &p) const;
    Color getColor() const;
    void setColor(const Color &rhs) {
        color = rhs;
    }
private:
    float radius;
    Vec3 center;
    Color color;
};

#endif // __SPHERE_H__
