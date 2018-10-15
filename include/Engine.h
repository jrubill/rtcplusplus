#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Color.h"
#include "Ray.h"
#include "Object.h"
#include <vector>
#include "Sphere.h"

class Engine {
public:
    Engine() : width(500), height(500), buffer() 
        { buffer.reserve(width * height); } 
    
    static Engine *getInstance();
    std::vector<Color>& getBuffer();
    Color raytrace(Ray&, float&, float&) const;
private:
    Engine(const Engine&) = delete;

    int width, height;
    std::vector<Color> buffer;
};

#endif // __ENGINE_H__
