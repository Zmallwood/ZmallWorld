// Copright 2024 Andreas Åkerberg

#include "system_menu.hpp"
#include "core/net/net_session.hpp"
#include "pch/pch.hpp"

namespace zw {
    void system_menu::render(std::shared_ptr<net_session> net_session) {

        net_session->add_message("clear;0;150;255");
        net_session->add_message("draw_text;ZmallWorld menu;0.05;0.1");
        net_session->add_message("draw_text;================;0.05;0.15");
        for (auto i = 0; i < menu_options_.size(); i++) {
            std::string text = menu_options_[i];
            if (i == selected_menu_option_)
                text += " <";
            std::string message = "draw_text;" + text + ";0.05;" + std::to_string(0.15 + (i + 1) * 0.05);

            net_session->add_message(message);
        }
    }

    void system_menu::select_up() {
        selected_menu_option_ = std::max(0, selected_menu_option_ - 1);
    }

    void system_menu::select_down() {
        selected_menu_option_ = std::min(1, selected_menu_option_ + 1);
    }

    void system_menu::apply_selection(std::shared_ptr<net_session> net_session) {
        switch (selected_menu_option_) {
        case 0:
            net_session->add_message("redirect;8082");
            net_session->do_write();
            break;
        case 1:
            net_session->add_message("redirect;8081");
            net_session->do_write();
            break;
        }
    }
}
