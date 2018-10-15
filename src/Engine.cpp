#include "Engine.h"

#include "Pointlight.h"

Engine *Engine::getInstance() {
    static Engine *instance = nullptr;
    if (!instance) instance = new Engine();
    return instance;
}

std::vector<Color>& Engine::getBuffer() {
    loadScene(); 
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
     
    //Sphere sphere(Vec3(250, 250, 400), 50);
    Pointlight light(Vec3(0,0,0));
    for (Object const *obj : objs) { 
        if (obj->intersect(ray,t)) {
            Vec3 hitpoint = ray.getOrigin() + ray.getDir() * t; 
        
            Vec3 l = light.getCenter() - hitpoint;
            Vec3 n = obj->getNormal(hitpoint);
        
            n.normalize();
            l.normalize();
        
            float dt = l.dot(n); 
            return Color( (obj->getColor()*0.4) + (Color(0, 200, 90) * dt)*0.7);
        }
    }
    return Color(0,0,0);
}

void Engine::loadScene() {
    objs.push_back(new Sphere(Vec3(250,250,400), 200));
}
