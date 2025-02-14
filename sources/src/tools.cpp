#include "../include/tools.hpp"

namespace Tools {
    size_t get1Dfrom2D(Position<int> pos, uint w) {
        return (pos.y * w) + pos.x;
    }

    size_t get1Dfrom2D(int x, int y, uint w) {
        return (y * w) + x;
    }
};