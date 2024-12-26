// Copyright 2024 Andreas Åkerberg

#include "gui_text_field.hpp"

namespace dw {
    gui_text_field::gui_text_field(float x, float y) : position_({x, y}) {}

    void gui_text_field::render_derived(std::shared_ptr<net_session> net_session) {
    }
}
