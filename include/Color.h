#ifndef __COLOR_H__
#define __COLOR_H__

#include "Vec3.h"

class Color : public Vec3 {
public:
    Color() : Vec3(0,0,0), a(1) {}
    Color(int rd, int gr, int bl, int al = 1) : Vec3(rd,gr,bl), a(al) {}
    Color(const Color &rhs) : Vec3(rhs.x, rhs.y, rhs.z), a(rhs.a) {}
    Color& operator=(const Color &rhs) {
        if (this == &rhs) return *this;
        x= rhs.x;
        y = rhs.y;
        z = rhs.z;
        a = rhs.a;
        return *this;
    }



    Color(Color &&rhs) : Vec3(rhs.x, rhs.y, rhs.z), a(rhs.a) {} 
    Color& operator=(Color &&rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        a = rhs.a;
        return *this;
    }
    

    const float getR() const { return x/255.0; }
    const float getG() const { return y/255.0; }
    const float getB() const { return z/255.0; }

private:
    int a;
};

#endif // __COLOR_H__
