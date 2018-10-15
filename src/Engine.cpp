#include "Engine.h"


Engine *Engine::getInstance() {
    static Engine *instance = nullptr;
    if (!instance) instance = new Engine();
    return instance;
}

std::vector<Color>& Engine::getBuffer() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float closest = 1000000;
            Vec3 orig(j,i,0);
            Vec3 dir(0,0,1000000);
            Ray ray(orig, dir);
            float t = 10000000;
            buffer.emplace_back(raytrace(ray,t,closest));
        }

    }
    return buffer;
}

Color Engine::raytrace(Ray &ray, float &t, float &closest) const {
    Sphere sphere(Vec3(250, 400, 400), 20);
    if (sphere.intersect(ray,t)) {
        Vec3 hitpoint = ray.getOrigin() + ray.getDir() * t;    
        return Color(0,100,150);
    }
    return Color(0,0,0);
}
