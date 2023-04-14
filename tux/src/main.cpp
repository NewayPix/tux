#include <iostream>

#include "core/game.hpp"
#include "core/sound/track.hpp"
#include "graphics/sdl/sprite.hpp"

int main() {
    using namespace Kokiri::Core;
    using namespace Kokiri::Graphics::SDL;

    Game game("Rafael Campos Nunes - 19/0098295", 1024, 600);

    Track bgm("assets/audio/stageState.ogg");
    Track effect("assets/audio/boom.wav");

    auto render = [&game](){
        Sprite sprite_tux(game.get_window(), "assets/img/ocean.jpg");
        sprite_tux.render(0,0);
    };

    game.bind(FunctionType::Render, render);

    effect.play(-1);
    bgm.play(1); // not working over here (linux)

    game.loop();

    return 0;
}