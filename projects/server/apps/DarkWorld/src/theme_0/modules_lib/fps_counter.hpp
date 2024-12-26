// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw
{
class net_session;

class fps_counter
{
  public:
    void update();
    void render(std::shared_ptr<net_session> net_session);

  private:
    int fps_{0};
    int frames_count_{0};
    unsigned long long ticks_last_update_{0};
};
} // namespace dw
