// Copyright 2024 Andreas Åkerberg

#include "time.hpp"

namespace dw
{
unsigned long long get_ticks()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}
} // namespace dw
