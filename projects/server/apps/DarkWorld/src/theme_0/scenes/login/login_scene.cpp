// Copyright 2024 Andreas Åkerberg

#include "login_scene.hpp"
#include "core/gui_core/gui.hpp"
#include "core/gui_core/gui_menu_option.hpp"
#include "core/net/net_session.hpp"
#include "core/session/engine.hpp"
#include "core/session/input/keyboard_input.hpp"
#include "core/session/scenes_core/scene_manager.hpp"

namespace dw {
    login_scene::login_scene() : i_scene() {
        auto login_option = std::make_shared<gui_menu_option>("Login", 0.5f, 0.6f);
        auto create_option = std::make_shared<gui_menu_option>("Create Account", 0.5f, 0.7f);
        get_gui()->add_child_component(login_option);
        get_gui()->add_child_component(create_option);
    }

    void login_scene::update_derived(std::shared_ptr<engine> engine) {
        if (engine->get_keyboard_input()->any_key_is_pressed_pick_result()) {
            engine->get_scene_manager()->go_to_scene("main_scene");
        }
    }

    void login_scene::render_derived(std::shared_ptr<net_session> net_session,
                                     std::shared_ptr<session_properties> session_properties) {
        draw_image(net_session, "dw_default_scene_background", 0.0f, 0.0f, 1.0f, 1.0f);
        draw_image(net_session, "dw_logo", 0.45f, 0.2f, 0.1f, 0.05f);
    }
}
