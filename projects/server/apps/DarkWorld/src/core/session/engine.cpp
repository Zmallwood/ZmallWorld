// Copyright 2024 Andreas Åkerberg

#include "engine.hpp"
#include "scenes_core/scene_manager.hpp"

namespace forr {
    engine::engine() : scene_manager_(std::make_shared<scene_manager>()) {
    }

    void engine::update() {
        scene_manager_->update();
    }

    void engine::render(std::shared_ptr<net_session> net_session) {
        scene_manager_->render(net_session);
    }
}
