// Copyright 2024 Andreas Åkerberg

#pragma once

namespace forr {
  class net_session;

  class world_view {
    public:
      void render(std::shared_ptr<net_session> net_session);
  };
}
