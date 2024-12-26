// Copyright 2024 Andreas Åkerberg

#pragma once

#include "gui_component.hpp"

namespace dw {
    class gui_text_field : public gui_component {
      public:
        gui_text_field(float x, float y);

        void render_derived(std::shared_ptr<net_session> net_session);

      private:
        pointf position_;
    };
}
