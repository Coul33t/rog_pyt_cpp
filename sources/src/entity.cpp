#include "../include/entity.hpp"

Entity::Entity() {

}

Entity::Entity(int x, int y, char chr, Colour col): x(x), y(y), chr(chr), col(col) {}

Entity::~Entity() = default;

void Entity::move(int dx, int dy) {
    x += dx;
    y += dy;
}