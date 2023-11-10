#include "../include/entity.hpp"

Entity::Entity() {

}

Entity::Entity(int x, int y, char chr, Colour fg_col, Colour bg_col): x(x), y(y), chr(chr), fg_col(fg_col), bg_col(bg_col) {}

Entity::~Entity() = default;

void Entity::move(int dx, int dy) {
    x += dx;
    y += dy;
}