// Copyright 2024 Andreas Åkerberg

#pragma once

#include "gui_component.hpp"

namespace dw {
    class gui_input_field : public gui_component {
      public:
        gui_input_field(float x, float y, float w, float h);

        void render_derived(std::shared_ptr<net_session> net_session);

      private:
        inline static const std::string k_background_image_name{"dw_input_field_background"};
        inline static const std::string k_cursor_image_name{"dw_input_field_cursor"};

        rectf bounds_;
    };
}
