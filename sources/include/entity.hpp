#ifndef _ROGPYTCPP_ENTITY_HPP_
#define _ROGPYTCPP_ENTITY_HPP_

#include "tools.hpp"

class Entity {
public:
    Entity();
    Entity(int x, int y, char chr='X', Colour col={255, 255, 255});
    ~Entity();

    void move(int dx, int dy);

    int x, y;
    Colour col;
    char chr;
};

#endif //_ROGPYTCPP_ENTITY_HPP_