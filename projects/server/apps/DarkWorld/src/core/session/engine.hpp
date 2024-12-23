// Copyright 2024 Andreas Åkerberg

#pragma once

namespace forr {
    class scene_manager;
    class net_session;
    class keyboard_input;

    class engine {
      public:
        engine();
        void update();
        void render(std::shared_ptr<net_session> net_session);

      private:
        std::shared_ptr<scene_manager> scene_manager_;
        std::shared_ptr<keyboard_input> keyboard_input_;
    };
}
