// Copyright 2024 Andreas Åkerberg

#include "intro_scene.hpp"
#include "core/net/net_session.hpp"
#include "core/session/engine.hpp"
#include "core/session/input/keyboard_input.hpp"
#include "core/session/scenes_core/scene_manager.hpp"

namespace dw
{
void intro_scene::update_derived(std::shared_ptr<engine> engine)
{
    if (engine->get_keyboard_input()->any_key_is_pressed_pick_result())
    {
        engine->get_scene_manager()->go_to_scene("login_scene");
    }
}

void intro_scene::render_derived(std::shared_ptr<net_session> net_session,
                                 std::shared_ptr<session_properties> session_properties)
{
    draw_image(net_session, "dw_default_scene_background", 0.0f, 0.0f, 1.0f, 1.0f);
    draw_image(net_session, "dw_logo", 0.4f, 0.2f, 0.2f, 0.1f);
    if (get_ticks() % 800 < 400)
        draw_text(net_session, "Press to start", 0.5f, 0.5f, 255, 100, 0, true);
}
} // namespace dw
