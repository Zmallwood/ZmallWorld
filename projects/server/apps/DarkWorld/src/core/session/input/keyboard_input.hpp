// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
  class keyboard_input {
  public:
    void register_key_press(int key_code);
    void register_key_release(int key_code);
    bool any_key_is_pressed_pick_result();
    
  private:
    std::set<int> pressed_keys_;
  };
}
