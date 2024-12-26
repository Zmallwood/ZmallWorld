// Copyright 2024 Andreas Åkerberg

#include "draw.hpp"
#include "core/net/net_session.hpp"

namespace dw {
    void clear(std::shared_ptr<net_session> net_session, int r, int g, int b) {
        net_session->add_message(std::string("clear;") + std::to_string(r) + ";" + std::to_string(g) + ";" +
                                 std::to_string(b));
    }

    void draw_image(std::shared_ptr<net_session> net_session, std::string_view image_name, float x, float y, float w,
                    float h) {
        net_session->add_message(std::string("draw_image;") + image_name.data() + ";" + std::to_string(x) + ";" +
                                 std::to_string(y) + ";" + std::to_string(w) + ";" + std::to_string(h));
    }
    void draw_text(std::shared_ptr<net_session> net_session, std::string_view text, float x, float y, int r, int g,
                   int b, bool center_align) {
        net_session->add_message(std::string("draw_text;") + text.data() + ";" + std::to_string(x) + ";" +
                                 std::to_string(y) + ";" + std::to_string(r) + ";" + std::to_string(g) + ";" +
                                 std::to_string(b) + ";" + std::to_string(center_align));
    }
}
