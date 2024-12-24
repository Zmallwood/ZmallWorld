// Copyright 2024 Andreas Åkerberg

#pragma once

#include "core/session/scenes_core/i_scene.hpp"

namespace dw {
  class login_scene : public i_scene
  {
  public:
    void update(std::shared_ptr<engine> engine) override;
    void render(std::shared_ptr<net_session> net_session) override;
  };
}
