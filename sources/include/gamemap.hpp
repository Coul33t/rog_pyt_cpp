#ifndef _ROGPYTCPP_GAMEMAP_H_
#define _ROGPYTCPP_GAMEMAP_H_

#include <iostream>
#include <vector>

#include "tile.hpp"

#include "tools.hpp"

#include "types.hpp"

class GameMap {
    GameMap(Size<uint> size);
    ~GameMap();

    void initVoid();

    void createDefaultMap();

    void createHWall(int x, int y, int w);
    void createVWall(int x, int y, int h);
    void createRoom(int x, int y, int w, int h);

    bool inBounds(int x, int y);

    Size<uint> size;
    std::vector<Tile> tiles;
    std::vector<Rectangle> rooms;
};

#endif