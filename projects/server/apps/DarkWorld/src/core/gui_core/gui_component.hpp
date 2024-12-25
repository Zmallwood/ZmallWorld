// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    class net_session;

    class gui_component {
      public:
        void update();
        void render(std::shared_ptr<net_session> session);
        virtual void update_derived() {
        }
        virtual void render_derived(std::shared_ptr<net_session> net_session) {
        }
        void add_child_component(std::shared_ptr<gui_component> component);

      private:
        std::vector<std::shared_ptr<gui_component>> child_components_;
    };
}
