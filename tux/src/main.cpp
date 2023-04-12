#include <iostream>

#include "core/game.hpp"

int main() {
    Kokiri::Core::Game game("Rafael Campos Nunes - 19/0098295", 800, 600);

    game.loop();

    return 0;
}