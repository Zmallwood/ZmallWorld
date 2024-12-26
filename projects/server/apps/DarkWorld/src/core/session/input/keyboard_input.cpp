// Copyright 2024 Andreas Åkerberg

#include "keyboard_input.hpp"

namespace dw
{
void keyboard_input::register_key_press(int key_code)
{
    pressed_keys_.insert(key_code);
}

void keyboard_input::register_key_release(int key_code)
{
    pressed_keys_.erase(key_code);
}

bool keyboard_input::any_key_is_pressed_pick_result()
{
    auto result = pressed_keys_.size() > 0;
    pressed_keys_.clear();
    return result;
}
} // namespace dw
