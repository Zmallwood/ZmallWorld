// Copyright 2024 Andreas Åkerberg

#include "world_view.hpp"
#include "core/net/net_session.hpp"
#include "theme_0/scenes/main/math/tile_grid_math.hpp"

namespace forr {
    void world_view::render(std::shared_ptr<net_session> net_session) {
      auto tile_size = tile_grid_math::calc_tile_size();
      for (auto y = 0; y < 11; y++) {
        for (auto x = 0; x < 11; x++) {
          auto tx = x*tile_size.w;
          auto ty = y*tile_size.h;
          auto tw = tile_size.w;
          auto th = tile_size.h;
          net_session->add_message("draw_image;ground_grass;" + std::to_string(tx) + ";" + std::to_string(ty) + ";" + std::to_string(tw) + ";" + std::to_string(th));
        }
      }
    }
}
