// Copyright 2024 Andreas Åkerberg

#pragma once

namespace forr {
  class net_session;
  class engine;

  class i_scene {
    public:
      virtual void update(std::shared_ptr<engine> engine) = 0;
      virtual void render(std::shared_ptr<net_session> net_session) = 0;
  };
}
