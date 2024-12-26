// Copyright 2024 Andreas Åkerberg

#include "i_scene.hpp"
#include "core/gui_core/gui.hpp"

namespace dw
{
i_scene::i_scene() : gui_(std::make_shared<gui>())
{
}

void i_scene::update(std::shared_ptr<engine> engine)
{
    gui_->update();
    update_derived(engine);
}

void i_scene::render(std::shared_ptr<net_session> net_session, std::shared_ptr<session_properties> session_properties)
{
    render_derived(net_session, session_properties);
    gui_->render(net_session);
}
} // namespace dw
