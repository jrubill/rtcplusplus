#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Color.h"
#include "Ray.h"
#include "Object.h"
#include <vector>
#include "Sphere.h"
#include <iostream>
#include <list>

class Engine {
public:
    Engine() : width(500), height(500), buffer(), objs() 
        { buffer.reserve(width * height); } 
    
    static Engine *getInstance();
    std::vector<Color>& getBuffer();
    Color raytrace(Ray&, float&, float&) const;
    void loadScene();
private:
    Engine(const Engine&) = delete;

    int width, height;
    std::vector<Color> buffer;
    std::list<Object *> objs;
};

#endif // __ENGINE_H__
