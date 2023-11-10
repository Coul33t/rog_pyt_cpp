#include "../include/engine.hpp"

Engine::Engine() {

}

Engine::~Engine() = default;

void Engine::init() {
    player = EntitiesFactory::createPlayer(5, 5);
    renderer.init();
}

void Engine::run() {
    int key = 0;
    terminal_refresh();

    while (terminal_peek() != TK_CLOSE) {

        key = 0;

        if (terminal_has_input()) {
            key = terminal_read();
        }

        switch(key) {
            case TK_UP :
                player.move(0, -1);
                break;

            case TK_DOWN :
                player.move(0, 1);
                break;

            case TK_LEFT :
                player.move(-1, 0);
                break;

            case TK_RIGHT :
                player.move(1, 0);
                break;

            case TK_P:
                renderer.render_ascii = !renderer.render_ascii;
                break;

            default: break;
        }
        terminal_clear();

        renderer.renderEntities(entities);
        renderer.renderEntity(player);

        terminal_refresh();
    }
}