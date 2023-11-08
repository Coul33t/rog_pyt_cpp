#include "../include/renderer.h"

Renderer::Renderer(int w, int h): w(w), h(h) {}

Renderer::~Renderer() = default;

void Renderer::init() {
    initConsole(w, h);
}

void Renderer::initConsole(uint w, uint h) {
    terminal_open();
    std::string size = "window: size=" + std::to_string(w) + "x" + std::to_string(h);
    terminal_set(size.c_str());
    //terminal_set("title='Project RLECS'");
    terminal_set("font: default");
    terminal_set("input: filter={keyboard}");
    terminal_color("black");
}

void Renderer::renderChar(uint x, uint y, char chr, Colour fg, Colour bg) {
    terminal_bkcolor(bg.toBLTRGB());
    terminal_color(fg.toBLTRGB());
    terminal_put_ext(x, y, 0, 0, chr);
}

void Renderer::renderString(uint x, uint y, std::string str, Colour fg, Colour bg) {
    terminal_bkcolor(bg.toBLTRGB());
    terminal_color(fg.toBLTRGB());
    terminal_print(x, y, str.c_str());
}

void Renderer::renderEntity(const Entity& ent) {
    renderChar(ent.x, ent.y, ent.chr, ent.col, ent.col);
}

void Renderer::renderEntities(const std::vector<Entity>& ent_vec) {
    for (auto& ent: ent_vec) {
        renderEntity(ent);
    }
}