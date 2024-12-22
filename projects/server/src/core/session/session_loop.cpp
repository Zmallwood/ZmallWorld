#include "session_loop.hpp"
#include "core/net/net_session.hpp"

namespace forr {
    session_loop::session_loop(std::shared_ptr<net_session> net_session) : net_session_(net_session) {
    }

    void session_loop::march() {
        switch (current_command_type_) {
        case command_types::read:
            net_session_->do_read();
            current_command_type_ = command_types::write;
            break;
        case forr::command_types::write:
            net_session_->add_message("clear;0;0;255");
            net_session_->add_message("draw_text;10;60;ZmallWorld menu:");
            for (auto i = 0; i < menu_options_.size(); i++) {
              std::string s = "draw_text;10;" + std::to_string(60+(i+1)*60) + ";" + menu_options_[i];
              net_session_->add_message(s);
            }
            //net_session_->do_write("render_finished");
            net_session_->do_write();
            current_command_type_ = command_types::read;
            march();
            break;
        }
    }
}
