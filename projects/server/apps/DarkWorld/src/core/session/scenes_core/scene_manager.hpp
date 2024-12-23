// Copyright 2024 Andreas Åkerberg

#pragma once

namespace forr {
    class i_scene;
    class net_session;
    class engine;

    class scene_manager {
      public:
        scene_manager();
        void update(std::shared_ptr<engine> engine);
        void render(std::shared_ptr<net_session> net_session);
        void go_to_scene(std::string_view scene_name);

      private:
        std::map<int, std::shared_ptr<i_scene>> scenes_;
        int current_scene_ {0};
    };
}
