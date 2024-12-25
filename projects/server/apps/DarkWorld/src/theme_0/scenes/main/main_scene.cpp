// Copyright 2024 Andreas Åkerberg

#include "main_scene.hpp"
#include "core/net/net_session.hpp"
#include "core/session/session_properties.hpp"
#include "theme_0/modules_lib/fps_counter.hpp"
#include "theme_0/modules_lib/world_view.hpp"

namespace dw {
    main_scene::main_scene()
        : world_view_(std::make_shared<world_view>()), fps_counter_(std::make_shared<fps_counter>()) {
    }

    void main_scene::update(std::shared_ptr<engine> engine) {
        fps_counter_->update();
    }

    void main_scene::render(std::shared_ptr<net_session> net_session,
                            std::shared_ptr<session_properties> session_properties) {
        clear(net_session, 0, 150, 255);
        world_view_->render(net_session, session_properties);
        fps_counter_->render(net_session);
    }
}
