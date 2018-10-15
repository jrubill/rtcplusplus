#ifndef __POINTLIGHT_H__
#define __POINTLIGHT_H__

#include "Vec3.h"
#include "Color.h"

class Pointlight {
public:
    Pointlight() : center(), color(255,255,255) {}
    Pointlight(Vec3 c) : center(c), color(255,255,255) {}
    Vec3 getCenter() const { return center; }
private:
    Vec3 center;
    Color color;

};

#endif // __POINTLIGHT_H__
