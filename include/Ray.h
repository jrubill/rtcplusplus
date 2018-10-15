#ifndef __RAY_H__
#define __RAY_H__

#include "Vec3.h"

class Ray {
public:
    Ray() : orig(), dir() {}
    const Vec3 getOrigin() const { return orig; }
    const Vec3 getDir() const { return dir; }
private:
    Vec3 orig, dir;
};

#endif // __RAY_H__
