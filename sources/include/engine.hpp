#ifndef _ROGPYTCPP_ENGINE_HPP_
#define _ROGPYTCPP_ENGINE_HPP_

#include <vector>

#include <SDL2/SDL.h>
#include "BearLibTerminal.h"

#include "entity.hpp"
#include "entities_factory.hpp"

#include "renderer.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void run();

    Renderer renderer;

    std::vector<Entity> entities;
    Entity player;
};

#endif //_ROGPYTCPP_ENGINE_HPP_