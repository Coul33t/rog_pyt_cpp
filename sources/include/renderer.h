#ifndef ROGUE_PYT_CPP_RENDERER_H
#define ROGUE_PYT_CPP_RENDERER_H

#include <vector>

#include "libtcod_no_warnings.hpp"
#include "BearLibTerminal.h"

#include "entity.hpp"

#include "tools.hpp"

class Renderer {
public:
    Renderer(int w = 80, int h = 45);
    ~Renderer();

    void init();

    void initConsole(uint w, uint h);

    void renderChar(uint x, uint y, char chr,Colour fg, Colour bg);
    void renderString(uint x, uint y, std::string str, Colour fg, Colour bg);

    void renderEntity(const Entity& ent);
    void renderEntities(const std::vector<Entity>& ent_vec);

    int w, h;
};
#endif //ROGUE_PYT_CPP_RENDERER_H
