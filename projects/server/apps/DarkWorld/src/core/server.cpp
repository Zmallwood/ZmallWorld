// Copyright 2024 Andreas Åkerberg

#include "server.hpp"
#include "core/net/net_server.hpp"

namespace dw {
    void server::run() {

        auto const address = boost::beast::net::ip::make_address("0.0.0.0");
        auto const port = static_cast<unsigned short>(8082);
        auto const threads = std::max<int>(1, 3);

        dw::net_server net_server;
        net_server.run(address, port, threads);
    }
}
