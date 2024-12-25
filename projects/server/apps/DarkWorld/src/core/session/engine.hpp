// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    class scene_manager;
    class net_session;
    class keyboard_input;
    class session_properties;

    class engine : public std::enable_shared_from_this<engine> {
      public:
        engine();
        void update();
        void render(std::shared_ptr<net_session> net_session, std::shared_ptr<session_properties> session_properties);

        auto get_scene_manager() {
            return scene_manager_;
        }

        auto get_keyboard_input() {
            return keyboard_input_;
        }

      private:
        std::shared_ptr<scene_manager> scene_manager_;
        std::shared_ptr<keyboard_input> keyboard_input_;
    };
}
