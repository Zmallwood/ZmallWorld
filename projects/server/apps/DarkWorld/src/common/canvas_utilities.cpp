// Copyright 2024 Andreas Åkerberg

#include "canvas_utilities.hpp"

namespace dw {
    float calc_aspect_ratio(int width, int height) {
        return static_cast<float>(width) / height;
    }

    float calc_aspect_ratio(size canvas_size) {
        return calc_aspect_ratio(canvas_size.w, canvas_size.h);
    }

    float convert_width_to_height(float width, float aspect_ratio) {
        return width * aspect_ratio;
    }

    float convert_height_to_width(float height, float aspect_ratio) {
        return height / aspect_ratio;
    }
}
