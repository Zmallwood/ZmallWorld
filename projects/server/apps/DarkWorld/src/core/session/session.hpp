// Copyright 2024 Andreas Åkerberg

#pragma once

namespace forr {
  class engine;
  class net_session;

  class session {
  public:
    session();
    void process(std::shared_ptr<net_session> net_session);
    void handle_message(std::string_view message);

  private:
    std::shared_ptr<engine> engine_;
  };
}
