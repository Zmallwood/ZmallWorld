// Copyright 2024 Andreas Åkerberg

#include "main_scene.hpp"
#include "core/net/net_session.hpp"
#include "modules/world_view.hpp"

namespace forr {
    main_scene::main_scene() : world_view_(std::make_shared<world_view>()) {
    }

    void main_scene::update(std::shared_ptr<engine> engine) {
    }

    void main_scene::render(std::shared_ptr<net_session> net_session) {
        net_session->add_message("clear;0;150;255");
        world_view_->render(net_session);
        net_session->do_write();
    }
}
