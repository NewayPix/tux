#include <iostream>
#include <utility>
#include <vector>

#include "core/game.hpp"
#include "core/event.hpp"
#include "core/types.hpp"
#include "core/functions.hpp"
#include "core/sound/track.hpp"
#include "core/debug/log.hpp"

#include "graphics/sdl/sprite.hpp"

int main() {
    using namespace Kokiri;
    using namespace Kokiri::Graphics::SDL;

    Game game("Rafael Campos Nunes - 19/0098295", 1024, 600);

    Track bgm("assets/audio/stageState.ogg");
    Track effect("assets/audio/boom.wav");

    std::vector<std::pair<v2<int>, Sprite*>> assets;

    Sprite background(game.get_window(), "assets/img/ocean.jpg");

    // user render function
    auto render = [&game, &background, &assets](){
        background.render(0, 0);

        for (const auto& asset : assets) {
            auto p = asset.first;
            auto s = asset.second;

            s->render(p.x, p.y);
        }
    };

    // user event function
    auto event = [&game, &assets]() {
        auto e = game.get_event();

        if (e.get()->is_mouse_click(Event::Mouse::LeftButton)) {
            auto p = e.get()->get_mouse_position();
            auto s = new Sprite(game.get_window(), "assets/img/penguinface.png");

            Log::info("click: ", p.x, p.y);

            assets.push_back(std::make_pair(p, s));
        }

        if (e.get()->is_key_down(Event::Key::M)) {
            Log::info("key M was pressed");
        }
    };

    game.bind(FunctionType::Event, event);
    game.bind(FunctionType::Render, render);

    effect.play(-1);
    bgm.play(1);

    game.loop();

    // clean everything
    for (const auto& asset : assets) {
        delete asset.second;
    }

    return 0;
}