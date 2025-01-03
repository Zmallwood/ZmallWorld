// Copyright 2024 Andreas Åkerberg

#include "fps_counter.hpp"
#include "core/net/net_session.hpp"

namespace dw {
    void fps_counter::update() {
        auto now = get_ticks();
        if (now > ticks_last_update_ + 1000) {
            fps_ = frames_count_;
            frames_count_ = 0;
            ticks_last_update_ = now;
        }
        frames_count_++;
    }

    void fps_counter::render(std::shared_ptr<net_session> net_session) {
        std::string fps_text = "FPS: " + std::to_string(fps_);
        draw_text(net_session, fps_text, 0.9f, 0.05f, 255, 255, 0);
    }
}
