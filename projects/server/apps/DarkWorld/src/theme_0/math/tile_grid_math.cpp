// Copyright 2024 Andreas Åkerberg

#include "tile_grid_math.hpp"
#include "theme_0/configuration/game_properties.hpp"

namespace dw {
    namespace tile_grid_math {
        sizef calc_tile_size(size canvas_size) {
            auto aspect_ratio = calc_aspect_ratio(canvas_size);
            auto tile_h = 1.0f / game_properties::k_num_tile_grid_rows;
            auto tile_w = convert_height_to_width(tile_h, aspect_ratio);

            return {tile_w, tile_h};
        }
    }
}
