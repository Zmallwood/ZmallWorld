// Copyright 2024 Andreas Åkerberg

#include "session.hpp"
#include "engine.hpp"
#include "input/keyboard_input.hpp"

namespace dw {
    session::session() : engine_(std::make_shared<engine>()) {
    }

    void session::process(std::shared_ptr<net_session> net_session) {
        while (true) {
            engine_->update();
            engine_->render(net_session);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    void session::handle_message(std::string_view message) {
        auto parts = split(message, ';');
        if (parts[0] == "key_press") {
            engine_->get_keyboard_input()->register_key_press(0);
        }
    }
}
