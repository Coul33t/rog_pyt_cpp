#ifndef _ROGPYTCPP_TILE_HPP_
#define _ROGPYTCPP_TILE_HPP_

#include "types.hpp"

struct Tile {
    bool walkable;
    bool transparent;
    char chr;
    ColoursVariations col;

    Tile(char chr): chr(chr) {};

    Tile(char chr, bool walkable, bool transparent, Colour fg, Colour bg): 
        chr(chr), walkable(walkable), transparent(transparent) {
        this->col = ColoursVariations(fg, bg);
    }

    Tile(bool walkable, bool transparent, Colour fg, Colour bg, Colour dark_fg, 
            Colour dark_bg, Colour light_fg, Colour light_bg): 
        chr(chr), walkable(walkable), transparent(transparent) {

        this->col = ColoursVariations(fg, bg, dark_fg, dark_bg, light_fg, light_bg);
    }
};

namespace TileFuncs {
    Tile getVoid() {
        return Tile(' ', true, true, Colour(0, 0, 0), Colour(0, 0, 0));
    }
    Tile getFloor() {
        return Tile('.', true, true, Colour(255, 255, 255), Colour(0, 0, 0));
    }

    Tile getWall() {
        return Tile('#', false, false, Colour(255, 255, 255), Colour(0, 0, 0));
    }
};

#endif