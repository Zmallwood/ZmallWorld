// Copyright 2024 Andreas Åkerberg

#pragma once

namespace forr {
    class scene_manager;
    class net_session;

    class engine {
      public:
        engine();
        void update();
        void render(std::shared_ptr<net_session> net_session);

      private:
        std::shared_ptr<scene_manager> scene_manager_;
    };
}
