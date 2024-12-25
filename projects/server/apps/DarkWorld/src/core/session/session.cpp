// Copyright 2024 Andreas Åkerberg

#include "session.hpp"
#include "engine.hpp"
#include "input/keyboard_input.hpp"
#include "session_properties.hpp"

namespace dw {
    session::session()
        : engine_(std::make_shared<engine>()), session_properties_(std::make_shared<session_properties>()) {
    }

    void session::process(std::shared_ptr<net_session> net_session) {
        while (true) {
            engine_->update();
            engine_->render(net_session, session_properties_);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void session::handle_message(std::string_view message) {
        auto parts = split(message, ';');
        if (parts[0] == "key_press") {
            engine_->get_keyboard_input()->register_key_press(0);
        } else if (parts[0] == "canvas_size") {
            auto w = std::stoi(parts[1].data());
            auto h = std::stoi(parts[2].data());
            session_properties_->set_canvas_size({w, h});
        }
    }
}
