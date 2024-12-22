// Copright 2024 Andreas Åkerberg

#include "server.hpp"
#include "net/net_server.hpp"
#include "pch/pch.hpp"

namespace forr {

    void server::run(boost::asio::ip::address address, unsigned short port, int threads) {
        forr::net_server net_server;
        net_server.run(address, port, threads);
    }
}
