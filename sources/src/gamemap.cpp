#include "../include/gamemap.hpp"

GameMap::GameMap(Size<uint> size) {
    this->tiles.reserve(size.w * size.h);
}

GameMap::~GameMap() {

}

void GameMap::initVoid() {
    for (size_t i = 0; i < this->tiles.size(); i++) {
        this->tiles[i] = TileFuncs::getVoid();
    }
}

void GameMap::createHWall(int x, int y, int w) {
    if (inBounds(x - 1, y - 1) && inBounds (x + w + 1, y + 1)) {
        for (size_t i = x; i < x + w; i++) {
            this->tiles[Tools::get1Dfrom2D(i, y, this->size.w)] = TileFuncs::getWall();
        }
    }
}

void GameMap::createVWall(int x, int y, int h) {
    if (inBounds(x - 1, y - 1) && inBounds (x + 1, y + h + 1)) {
        for (size_t i = y; i < y + h; i++) {
            this->tiles[Tools::get1Dfrom2D(x, i, this->size.w)] = TileFuncs::getWall();
        }
    }
}

void GameMap::createRoom(int x, int y, int w, int h) {
    if (inBounds(x - 1, y - 1) && inBounds(x + w + 1, y + h + 1)) {
        createHWall(x - 1,      y - 1,      w + 1);
        createHWall(x - 1,      y - 1 + h,  w + 1);
        createVWall(x - 1,      y - 1,      h + 1);
        createVWall(x - 1 + w,  y - 1,      h + 1);

        for (size_t i = x; i < x + w; i++) {
            for (size_t j = y; j < y + h; j++) {
                this->tiles[Tools::get1Dfrom2D(i, j, this->size.w)] = TileFuncs::getFloor();
            }
        }
    }

    else {
        std::cout << "INFO [OUT OF BOUNDS]: can't create room with size x=" << x << ", y=" << y << ", w=" << w << ", h= " << h <<"." << std::endl;
    }
}

void GameMap::createDefaultMap() {
    this->tiles.clear();
    createRoom(5, 10, 20, 5);
}

bool GameMap::inBounds(int x, int y) {
    return ((x >= 0 && x < this->size.w) && (y >= 0 && y < this->size.h));
}