// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    float calc_aspect_ratio(int width, int height);
    float calc_aspect_ratio(size canvas_size);
    float convert_width_to_height(float width, float aspect_ratio);
    float convert_height_to_width(float height, float aspect_ratio);
}
