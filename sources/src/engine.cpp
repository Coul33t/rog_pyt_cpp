#include "../include/engine.hpp"

Engine::Engine() {

}

Engine::~Engine() = default;

void Engine::init() {
    player = EntitiesFactory::createPlayer(5, 5);
    renderer.init();
}

void Engine::run() {
    while (terminal_peek() != TK_CLOSE) {
        renderer.renderEntities(entities);
        renderer.renderEntity(player);

        terminal_refresh();
    }
}