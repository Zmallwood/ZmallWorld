// Copyright 2024 Andreas Åkerberg

#include "intro_scene.hpp"
#include "core/net/net_session.hpp"

namespace forr {
    void intro_scene::update() {
    }

    void intro_scene::render(std::shared_ptr<net_session> net_session) {
      net_session->add_message("clear;0;150;255");
      net_session->add_message("draw_image;default_scene_background;0.0;0.0;1.0;1.0");
      net_session->add_message("draw_image;dark_world_logo;0.4;0.2;0.2;0.1");
      net_session->do_write();
    }
}
