// Copyright 2024 Andreas Åkerberg

#include "world_view.hpp"
#include "core/net/net_session.hpp"

namespace forr {
    void world_view::render(std::shared_ptr<net_session> net_session) {
      for (auto y = 0; y < 11; y++) {
        for (auto x = 0; x < 11; x++) {
          net_session->add_message("draw_image;ground_grass;0.0;0.0;1.0;1.0");
        }
      }
    }
}
