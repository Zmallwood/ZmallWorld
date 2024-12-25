// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    class net_session;
    void clear(std::shared_ptr<net_session> net_session, int r, int g, int b);
    void draw_image(std::shared_ptr<net_session> net_session, std::string_view image_name, float x, float y, float w,
                    float h);
    void draw_text(std::shared_ptr<net_session> net_session, std::string_view text, float x, float y, int r = 255,
                   int g = 255, int b = 255);
}
