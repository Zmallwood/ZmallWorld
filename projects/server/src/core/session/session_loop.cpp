// Copright 2024 Andreas Åkerberg

#include "session_loop.hpp"
#include "core/net/net_session.hpp"
#include "system_menu/system_menu.hpp"

namespace forr {
    session_loop::session_loop(std::shared_ptr<net_session> net_session)
        : net_session_(net_session), system_menu_(std::make_shared<system_menu>()) {
    }

    void session_loop::update() {
        auto message = net_session_->get_last_message();
        auto parts = split(message, ';');
        if (parts[0] == "key_press") {
            auto key = std::stoi(parts[1].data());
            switch (key) {
            case key_codes::k_arrow_up:
                system_menu_->select_up();
                break;
            case key_codes::k_arrow_down:
                system_menu_->select_down();
                break;
            case key_codes::k_enter:
                system_menu_->apply_selection(net_session_);
                break;
            }
        }
    }

    void session_loop::render() {
        system_menu_->render(net_session_);
        net_session_->do_write();
        net_session_->do_read();
    }
}
