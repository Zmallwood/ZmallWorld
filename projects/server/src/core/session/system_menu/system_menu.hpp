// Copright 2024 Andreas Åkerberg

#pragma once

namespace forr {
    class net_session;

    class system_menu {
      public:
        void render(std::shared_ptr<net_session> net_session);
        void select_up();
        void select_down();

      private:
        std::vector<std::string> menu_options_ = {"DarkWorld", "ZmallSim"};
        int selected_menu_option_{0};
    };
}
