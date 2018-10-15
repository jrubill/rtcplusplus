#include "Sphere.h"

bool Sphere::intersect(Ray &r, float &t) const {
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

Vec3 Sphere::getNormal(Vec3 &p) const {
    return ((p - center) / radius);
}

Color Sphere::getColor() const {
    return color;
}

Vec3 Sphere::getCenter() const {
    return center;
}
