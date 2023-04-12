#include <iostream>

#include "core/game.hpp"

int main() {
    Kokiri::Core::Game game("Tux", 800, 600);

    game.loop();

    return 0;
}