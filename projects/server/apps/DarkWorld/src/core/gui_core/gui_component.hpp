// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    class gui_component {
      public:
        void update();
        void render();
        virtual void update_derived() {
        }
        virtual void render_derived() {
        }

      private:
    };
}
