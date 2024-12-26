// Copyright 2024 Andreas Åkerberg

#pragma once

#include "gui_component.hpp"

namespace dw {
    class gui_menu_option : public gui_component {
      public:
        gui_menu_option(std::string_view text, float x, float y);

        void render_derived(std::shared_ptr<net_session> net_session) override;

      private:
        std::string text_;
        pointf position_;
    };
}
