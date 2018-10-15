#ifndef __RAY_H__
#define __RAY_H__

#include "Vec3.h"

class Ray {
public:
    Ray() : orig(), dir() {}
    Ray(Vec3 &o, Vec3 &d) : orig(o), dir(d) {}
    Vec3 getOrigin() const { return orig; }
    Vec3 getDir() const { return dir; }
private:
    Vec3 orig, dir;
};

#endif // __RAY_H__
