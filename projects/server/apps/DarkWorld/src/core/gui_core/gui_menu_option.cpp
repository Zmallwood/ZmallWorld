// Copyright 2024 Andreas Åkerberg

#include "gui_menu_option.hpp"

namespace dw
{
gui_menu_option::gui_menu_option(std::string_view text, float x, float y) : text_(text), position_({x, y})
{
}

void gui_menu_option::render_derived(std::shared_ptr<net_session> net_session)
{
    draw_text(net_session, text_, position_.x, position_.y, 255, 200, 0, true);
}
} // namespace dw
