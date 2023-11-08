#ifndef _ROGPYTCPP_TOOL_HPP_
#define _ROGPYTCPP_TOOL_HPP_

#include "BearLibTerminal.h"

typedef unsigned int uint;

struct Colour {
    uint r, g, b;
    uint hex;

    Colour() {
        r = 0;
        g = 0;
        b = 0;
        hex = 0;
    }

    Colour(uint r, uint g, uint b) {
        this->r = r;
        this->g = g;
        this->b = b;
        this-> hex = (r << 16) | (g << 8) | b;
    }

    color_t toBLTRGB() {
        return color_from_argb(255, r, g, b);
    }
};

#endif //_ROGPYTCPP_TOOL_HPP_