#include "Engine.h"

#include "Pointlight.h"

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
            Vec3 dir(0,0,1000000000);
            Ray ray(orig, dir);
            float t = 10000000;
            buffer.emplace_back(raytrace(ray,t,closest));
        }

    }
    return buffer;
}

Color Engine::raytrace(Ray &ray, float &t, float &closest) const {
    Sphere sphere(Vec3(250, 250, 400), 50);
    Pointlight light(Vec3(0,0,0));
    if (sphere.intersect(ray,t)) {
        Vec3 hitpoint = ray.getOrigin() + ray.getDir() * t; 
        
        Vec3 l = light.getCenter() - hitpoint;
        Vec3 n = sphere.getNormal(hitpoint);
        
        n.normalize();
        l.normalize();
        
        float dt = l.dot(n); 
        return Color( (sphere.getColor()*0.4) + (Color(0, 200, 90) * dt)*0.7);
    }
    return Color(0,0,0);
}
