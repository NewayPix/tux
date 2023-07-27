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

    auto level = new Scene(game.get_window(), "level");
    auto menu = new Scene(game.get_window(), "menu");
    auto over = new Scene(game.get_window(), "over");

    game.add_scene(menu);
    game.add_scene(level);
    game.add_scene(over);

    game.set_active_scene("level");

    game.load(Game::Resource("bgm", "assets/audio/stageState.ogg", ComponentType::Soundtrack));
    game.load(Game::Resource("shot", "assets/audio/boom.wav", ComponentType::Soundtrack));
    game.load(Game::Resource("background", "assets/img/ocean.jpg", ComponentType::Sprite));
    game.load(Game::Resource("penguin", "assets/img/penguin.png", ComponentType::Sprite));

    Entity::EntityProperties world_properties("background");
    world_properties.size.x = 1024;
    world_properties.size.y = 600;

    Entity world(world_properties);

    auto b = game.retrieve("background");
    auto m = game.retrieve("bgm");

    if (b == nullptr || m == nullptr) {
        Log::error("resource is null");
        return 1;
    }

    world.add_component(b);
    world.add_component(m);

    auto p = dynamic_cast<Sprite*>(game.retrieve("penguin"));

    Entity::EntityProperties player_properties("player");
    player_properties.size.x = p->get_width();
    player_properties.size.y = p->get_height();

    Entity player(player_properties);

    player.add_component(game.retrieve("penguin"));

    // rendering order is VERY important
    level->add_entity(&player);
    level->add_entity(&world);

    level->bind(FunctionType::Render, [&game](){});

    level->bind(FunctionType::Event, [&game, &player]() {
        auto e = game.get_event();

        if (e.get()->is_mouse_click(Event::Mouse::LeftButton)) {
            auto p = e.get()->get_mouse_position();

            player.set_position(p);
        }
    });

    game.loop();

    return 0;
}