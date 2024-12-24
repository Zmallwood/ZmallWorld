// Copright 2024 Andreas Åkerberg

#pragma once

namespace dw {
    template <class T>
    T &_() {
        static T instance;
        return instance;
    }
}
