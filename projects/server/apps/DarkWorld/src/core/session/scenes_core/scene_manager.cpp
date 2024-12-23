// Copyright 2024 Andreas Åkerberg

#include "scene_manager.hpp"
#include "theme_0/scenes/intro/intro_scene.hpp"

namespace forr {
    scene_manager::scene_manager() {
        scenes_.insert({hash("intro_scene"), std::make_shared<intro_scene>()});
        current_scene_ = hash("intro_scene");
    }

    void scene_manager::update() {
        if (scenes_.contains(current_scene_))
            scenes_.at(current_scene_)->update();
    }

    void scene_manager::render(std::shared_ptr<net_session> net_session) {
        if (scenes_.contains(current_scene_))
            scenes_.at(current_scene_)->render(net_session);
    }
}
