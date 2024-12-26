// Copyright 2024 Andreas Åkerberg

#include "gui_label.hpp"

namespace dw {
    gui_label::gui_label(std::string_view text, float x, float y, bool center_aligned)
        : text_(text), position_({x, y}), center_aligned_(center_aligned) {
    }

    void gui_label::render_derived(std::shared_ptr<net_session> net_session) {
        draw_text(net_session, text_, position_.x, position_.y, 255, 200, 0, center_aligned_);
    }
}
