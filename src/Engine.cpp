#include "Engine.h"


Engine *Engine::getInstance() {
    static Engine *instance = nullptr;
    if (!instance) instance = new Engine();
    return instance;
}

std::vector<Color>& Engine::getBuffer() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            buffer.emplace_back(150,70,255);
        }

    }
    return buffer;
}

Color Engine::raytrace(Ray &r, float &t, float &closest) {

}
