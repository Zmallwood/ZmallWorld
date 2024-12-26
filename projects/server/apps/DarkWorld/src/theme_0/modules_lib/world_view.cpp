// Copyright 2024 Andreas Åkerberg

#include "world_view.hpp"
#include "core/net/net_session.hpp"
#include "core/session/session_properties.hpp"
#include "theme_0/configuration/game_properties.hpp"
#include "theme_0/math/tile_grid_math.hpp"

namespace dw {
    void world_view::render(std::shared_ptr<net_session> net_session,
                            std::shared_ptr<session_properties> session_properties) {
        auto tile_size = tile_grid_math::calc_tile_size(session_properties->get_canvas_size());
        auto num_rows = game_properties::k_num_tile_grid_rows;
        for (auto y = 0; y < num_rows; y++) {
            for (auto x = 0; x < num_rows; x++) {
                auto tx = x * tile_size.w;
                auto ty = y * tile_size.h;
                auto tw = tile_size.w;
                auto th = tile_size.h;
                draw_image(net_session, "dw_ground_grass", tx, ty, tw, th);
                if (x == 5 && y == 5) {
                    draw_image(net_session, "dw_player", tx, ty, tw, th);
                }
            }
        }
    }
}
