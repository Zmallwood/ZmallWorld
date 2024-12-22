// Copright 2024 Andreas Åkerberg

#pragma once

namespace forr {
  class net_session;
  class system_menu;

  class session_loop {
  public:
    session_loop(std::shared_ptr<net_session> session);

    void update();
    void render();

  private:
    std::shared_ptr<net_session> net_session_;
    std::shared_ptr<system_menu> system_menu_;
  };
}
