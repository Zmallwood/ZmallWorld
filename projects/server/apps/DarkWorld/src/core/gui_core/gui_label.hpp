// Copyright 2024 Andreas Åkerberg

#pragma once

#include "gui_component.hpp"

namespace dw
{
class gui_label : public gui_component
{
  public:
    gui_label(std::string_view text, float x, float y, bool center_aligned = false);

    void render_derived(std::shared_ptr<net_session> net_session) override;

  private:
    std::string text_;
    pointf position_;
    bool center_aligned_;
};
} // namespace dw
