// Copright 2024 Andreas Åkerberg

#include "utilities.hpp"

namespace forr {
    void fail(boost::beast::error_code ec, char const *what) {
        std::cerr << what << ": " << ec.message() << "\n";
    }
}
