// Copyright 2024 Andreas Åkerberg

#pragma once

namespace forr {
    class i_scene;
    class net_session;

    class scene_manager {
      public:
        scene_manager();
        void update();
        void render(std::shared_ptr<net_session> net_session);

      private:
        std::map<int, std::shared_ptr<i_scene>> scenes_;
        int current_scene_ {0};
    };
}
