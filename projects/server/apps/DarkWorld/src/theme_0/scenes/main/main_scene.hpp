// Copyright 2024 Andreas Åkerberg

#pragma once

#include "core/session/scenes_core/i_scene.hpp"

namespace dw {
    class world_view;
    class fps_counter;
    class session_properties;

    class main_scene : public i_scene {
      public:
        main_scene();

        void update_derived(std::shared_ptr<engine> engine) override;
        void render_derived(std::shared_ptr<net_session> net_session,
                    std::shared_ptr<session_properties> session_properties) override;

      private:
        std::shared_ptr<world_view> world_view_;
        std::shared_ptr<fps_counter> fps_counter_;
    };
}
