// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw
{
class engine;
class net_session;
class session_properties;

class session
{
  public:
    session();
    void process(std::shared_ptr<net_session> net_session);
    void handle_message(std::shared_ptr<net_session> net_session, std::string_view message);

  private:
    std::shared_ptr<engine> engine_;
    std::shared_ptr<session_properties> session_properties_;
};
} // namespace dw
