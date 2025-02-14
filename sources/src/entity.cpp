#include "../include/entity.hpp"

Entity::Entity() {

}

Entity::Entity(int x, int y, char chr, Colour fg_col, Colour bg_col): x(x), y(y), chr(chr) {
    this->col.fg = fg_col;
    this->col.bg = bg_col;
}

Entity::~Entity() = default;

void Entity::move(int dx, int dy) {
    x += dx;
    y += dy;
}