#include "Sphere.h"

bool Sphere::intersect(Ray &r, float &t) {
    Vec3 v = r.getOrigin() - center;
    Vec3 dir = r.getDir();
    float a = dir.dot(dir);
    float b = 2 * v.dot(dir);
    float c = v.dot(v) - radius * radius;
    
    
    float disc = b * b - 4 * a * c;
    if (disc <= 0) return false;

    float root = sqrt(disc);
    t = (-b - root);
    if ( t < 0 ) {
        t = (-b + root);
        if (t < 0) return false;
    }
    t /= 2*a;
    return true;
}
