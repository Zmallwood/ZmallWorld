// Copyright 2024 Andreas Åkerberg

#include "scene_manager.hpp"
#include "theme_0/scenes/intro/intro_scene.hpp"
#include "theme_0/scenes/login/login_scene.hpp"
#include "theme_0/scenes/main/main_scene.hpp"

namespace forr {
    scene_manager::scene_manager() {
        scenes_.insert({hash("intro_scene"), std::make_shared<intro_scene>()});
        scenes_.insert({hash("login_scene"), std::make_shared<login_scene>()});
        scenes_.insert({hash("main_scene"), std::make_shared<main_scene>()});
        current_scene_ = hash("intro_scene");
    }

    void scene_manager::update(std::shared_ptr<engine> engine) {
        if (scenes_.contains(current_scene_))
            scenes_.at(current_scene_)->update(engine);
    }

    void scene_manager::render(std::shared_ptr<net_session> net_session) {
        if (scenes_.contains(current_scene_))
            scenes_.at(current_scene_)->render(net_session);
    }

    void scene_manager::go_to_scene(std::string_view scene_name) {
      current_scene_ = hash(scene_name);
    }
}
