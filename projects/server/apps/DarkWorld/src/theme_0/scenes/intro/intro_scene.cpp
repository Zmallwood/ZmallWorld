// Copyright 2024 Andreas Åkerberg

#include "intro_scene.hpp"
#include "core/net/net_session.hpp"
#include "core/session/engine.hpp"
#include "core/session/scenes_core/scene_manager.hpp"
#include "core/session/input/keyboard_input.hpp"

namespace dw {
    void intro_scene::update(std::shared_ptr<engine> engine) {
      if (engine->get_keyboard_input()->any_key_is_pressed()) {
        engine->get_scene_manager()->go_to_scene("login_scene");
      }
    }

    void intro_scene::render(std::shared_ptr<net_session> net_session) {
      net_session->add_message("clear;0;150;255");
      net_session->add_message("draw_image;default_scene_background;0.0;0.0;1.0;1.0");
      net_session->add_message("draw_image;dark_world_logo;0.4;0.2;0.2;0.1");
      net_session->add_message("draw_text;Press to start;400;300;255;150;0");
      net_session->do_write();
    }
}
