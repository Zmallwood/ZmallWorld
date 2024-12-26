// Copyright 2024 Andreas Åkerberg

#include "gui_component.hpp"

namespace dw {
    void gui_component::update() {
        update_derived();
        for (auto component : child_components_)
            component->update();
    }

    void gui_component::render(std::shared_ptr<net_session> net_session) {
        render_derived(net_session);
        for (auto component : child_components_)
            component->render(net_session);
    }

    void gui_component::add_child_component(std::shared_ptr<gui_component> component) {
        child_components_.push_back(component);
    }
}
