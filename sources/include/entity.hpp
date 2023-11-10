#ifndef _ROGPYTCPP_ENTITY_HPP_
#define _ROGPYTCPP_ENTITY_HPP_

#include "tools.hpp"

class Entity {
public:
    Entity();
    Entity(int x, int y, char chr='X', Colour fg_col={255, 255, 255, 255}, Colour bg_col={0, 0, 0, 0});
    ~Entity();

    void move(int dx, int dy);

    int x, y;
    Colour fg_col;
    Colour bg_col;
    char chr;
};

#endif //_ROGPYTCPP_ENTITY_HPP_