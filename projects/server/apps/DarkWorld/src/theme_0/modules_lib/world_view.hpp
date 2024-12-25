// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    class net_session;
    class session_properties;

        class world_view {
      public:
        void render(std::shared_ptr<net_session> net_session, std::shared_ptr<session_properties> session_properties);
    };
}
