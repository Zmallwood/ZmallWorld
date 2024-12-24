// Copyright 2024 Andreas Åkerberg

#include "tile_grid_math.hpp"
#include "theme_0/scenes/main/configuration/game_properties.hpp"

namespace forr {
    namespace tile_grid_math {
        sizef calc_tile_size() {
          auto tile_h = 1.0f/game_properties::k_num_tile_grid_rows;

            return {tile_h, tile_h};
        }
    }
}
