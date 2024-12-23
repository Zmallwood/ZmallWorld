// Copyright 2024 Andreas Åkerberg

#include "engine.hpp"
#include "input/keyboard_input.hpp"
#include "scenes_core/scene_manager.hpp"

namespace forr {
    engine::engine()
        : scene_manager_(std::make_shared<scene_manager>()), keyboard_input_(std::make_shared<keyboard_input>()) {
    }

    void engine::update() {
        scene_manager_->update(shared_from_this());
    }

    void engine::render(std::shared_ptr<net_session> net_session) {
        scene_manager_->render(net_session);
    }
}
