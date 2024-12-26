// Copyright 2024 Andreas Åkerberg

#include "gui_input_field.hpp"

namespace dw
{
gui_input_field::gui_input_field(float x, float y, float w, float h) : bounds_({x, y, w, h})
{
}

void gui_input_field::render_derived(std::shared_ptr<net_session> net_session)
{
    draw_image(net_session, k_background_image_name, bounds_.x, bounds_.y, bounds_.w, bounds_.h);
}
} // namespace dw
