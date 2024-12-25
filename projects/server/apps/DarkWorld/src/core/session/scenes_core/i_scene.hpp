// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    class net_session;
    class engine;
    class session_properties;

    class i_scene {
      public:
        virtual void update(std::shared_ptr<engine> engine) = 0;
        virtual void render(std::shared_ptr<net_session> net_session,
                            std::shared_ptr<session_properties> session_properties) = 0;
    };
}
