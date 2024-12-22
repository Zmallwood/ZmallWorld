#pragma once

namespace forr {
    template <class T>
    T &_() {
        static T instance;
        return instance;
    }
}
