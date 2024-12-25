// Copyright 2024 Andreas Åkerberg

#pragma once

namespace dw {
  class session_properties {
    public:
      auto get_canvas_size() const {
        return canvas_size_;
      }

      void set_canvas_size(size value) {
        canvas_size_ = value;
      }
      
    private:
      size canvas_size_;
  };
}
