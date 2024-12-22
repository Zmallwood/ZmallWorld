// Copright 2024 Andreas Åkerberg

#pragma once
#include "command_types.hpp"

namespace forr {
  class net_session;

  class session_loop {
  public:
    session_loop(std::shared_ptr<net_session> session);

    void march();

  private:
    command_types current_command_type_ = command_types::read;
    std::shared_ptr<net_session> net_session_;
    std::vector<std::string> menu_options_ = {"DarkWorld", "ZmallSim"};
    int active_menu_option_ {0};
  };
}
