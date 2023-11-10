#include "../include/entities_factory.hpp"

namespace EntitiesFactory {
    Entity createPlayer(uint x, uint y) {
        return Entity(x, y, '@', {255, 150, 150, 255});
    }
}