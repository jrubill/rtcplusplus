#ifndef __VEC3_H__
#define __VEC3_H__

class Vec3 {
public:
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3 &rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}
    Vec3(Vec3 &&rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}

    const float getX() const { return x; }
    const float getY() const { return y; }
    const float getZ() const { return z; }


    // overloading operators
    void operator+=(const Vec3 &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
    }
    void operator-=(const Vec3 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
    }

    void operator*=(const Vec3 &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
    }

    void operator*=(const float scale) {
        x *= scale;
        y *= scale;
        z *= scale;
    }

    void operator/=(const float scale) {
        x /= scale;
        y /= scale;
        z /= scale;
    }

    Vec3 operator+(const Vec3 &rhs) const {
        return Vec3(x + rhs.y, y + rhs.y, z + rhs.z);
    }

    Vec3 operator-(const Vec3 &rhs) const {
        return Vec3(x - rhs.y, y - rhs.y, z - rhs.z);
    }

    Vec3 operator*(const float scale) {
        return Vec3(x * scale, y * scale, z * scale);
    }

    Vec3 operator/(const float scale) {
        return Vec3(x * scale, y * scale, z * scale);
    }

    // added operators
    Vec3 cross(const Vec3 &rhs) const {
        return Vec3(y*rhs.z - rhs.y*z, rhs.x*z-x*rhs.z, x*rhs.y-rhs.x*y);
    }

    float dot(const Vec3 &rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    float det3(const Vec3 &v1, const Vec3 &v2) const {
        float a = x *    (v1.y * v2.z - v2.y * v1.z);
        float b = v1.x * (y * v2.z    - v2.y * z);
        float c = v2.x * (y *v2.z     - z * v1.y);
        return a - b + c;
    }

protected:
    float x, y, z;
};

#endif // __VEC3_H__
