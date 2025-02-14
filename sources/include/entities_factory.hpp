#ifndef _ROGPYTCPP_ENTITIES_FACTORY_
#define _ROGPYTCPP_ENTITIES_FACTORY_

#include "entity.hpp"
#include "tools.hpp"

namespace EntitiesFactory {
    Entity createPlayer(uint x, uint y);
    Entity createTestNPC(uint x, uint y);
};

#endif //_ROGPYTCPP_ENTITIES_FACTORY_