// Copright 2024 Andreas Åkerberg

#include "system_menu.hpp"
#include "core/net/net_session.hpp"
#include "pch/pch.hpp"

namespace forr {
    void system_menu::render(std::shared_ptr<net_session> net_session) {

        net_session->add_message("clear;0;150;255");
        net_session->add_message("draw_text;10;60;ZmallWorld menu:");
        net_session->add_message("draw_text;10;120;================");
        for (auto i = 0; i < menu_options_.size(); i++) {
            std::string s = "draw_text;10;" + std::to_string(120 + (i + 1) * 60) + ";* " + menu_options_[i];
            if (i == selected_menu_option_)
                s += " <";
            net_session->add_message(s);
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
