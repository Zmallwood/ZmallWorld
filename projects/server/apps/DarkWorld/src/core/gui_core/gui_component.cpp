// Copyright 2024 Andreas Åkerberg

#include "gui_component.hpp"

namespace dw {
    void gui_component::update() {
        update_derived();
    }

    void gui_component::render() {
        render_derived();
    }
}
