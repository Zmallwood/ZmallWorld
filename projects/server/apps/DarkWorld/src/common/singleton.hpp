// Copright 2024 Andreas Åkerberg

#pragma once

namespace dw
{
template <class T> T &get_singleton()
{
    static T instance;
    return instance;
}
} // namespace dw
