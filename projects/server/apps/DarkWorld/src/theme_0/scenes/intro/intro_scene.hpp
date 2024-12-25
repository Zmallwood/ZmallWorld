// Copyright 2024 Andreas Åkerberg

#pragma once

#include "core/session/scenes_core/i_scene.hpp"

namespace dw {
    class session_properties;

    class intro_scene : public i_scene {
      public:
        void update_derived(std::shared_ptr<engine> engine) override;
        void render_derived(std::shared_ptr<net_session> net_session,
                    std::shared_ptr<session_properties> session_properties) override;
    };
}
