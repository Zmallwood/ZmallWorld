// Copyright 2024 Andreas Åkerberg

#pragma once

#include "core/session/scenes_core/i_scene.hpp"

namespace forr {
  class login_scene : public i_scene
  {
  public:
    void update() override;
    void render(std::shared_ptr<net_session> net_session) override;
  };
}
