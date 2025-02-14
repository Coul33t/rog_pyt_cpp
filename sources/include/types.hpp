#ifndef _ROGPYTCPP_TYPES_HPP_
#define _ROGPYTCPP_TYPES_HPP_

#include "BearLibTerminal.h"

// Shortcut because I'm lazy :)
typedef unsigned int uint;

// ----- COLOUR TYPES -----
struct Colour {
    uint8_t r, g, b, a; // value range is 0 -> 255 = 8bits
    uint8_t hex; // max range is 000000 -> FFFFFF = 6 * 4 bits = 24 bits

    Colour() {
        r = 0;
        g = 0;
        b = 0;
        a = 255;
        hex = 0;
    }

    Colour(uint8_t r, uint8_t g, uint8_t b) {
        this->r = r;
        this->g = g;
        this->b = b;
        this-> hex = (r << 16) | (g << 8) | b;
        a = 255;
    }

    Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this-> hex = (r << 16) | (g << 8) | b;
        this->a = a;
    }

    color_t toBLTRGB() {
        return color_from_argb(a, r, g, b);
    }
};


struct ColoursVariations {
    Colour bg, fg, dark_bg, dark_fg, light_bg, light_fg;

    ColoursVariations() {};

    ColoursVariations(Colour fg, Colour bg) {
        this->fg = fg;
        this->bg = bg;
    }

    ColoursVariations(Colour fg, Colour bg, Colour dark_fg, Colour dark_bg, Colour light_fg, Colour light_bg) {
        this->fg = fg;
        this->bg = bg;
        this->dark_fg = dark_fg;
        this->dark_bg = dark_bg;
        this->light_fg = light_fg;
        this->light_bg = light_bg;
    }
};




// ----- GEOMETRIC TYPES -----
template <typename T>
struct Point {
    T x, y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(T x, T y): x(x), y(y) {}
};


template <typename T>
struct Position {
    T x, y;

    Position() {
        x = 0;
        y = 0;
    }

    Position(T x, T y): x(x), y(y) {}
};


template <typename T>
struct Size {
    T w, h;

    Size() {
        w = 0;
        h = 0;
    }

    Size(T w, T h): w(w), h(h) {}
};


struct Rectangle {
    int x, y, w, h, x2, y2;

    Rectangle() = default;

    Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {
        x2 = x + w;
        y2 = y + h;
    }

    Rectangle(const Rectangle& other_rect) {
        x = other_rect.x;
        y = other_rect.y;
        w = other_rect.w;
        h = other_rect.h;
        x2 = other_rect.x2;
        y2 = other_rect.y2;
    }
};

#endif