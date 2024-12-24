// Copright 2024 Andreas Åkerberg

#include "net_server.hpp"
#include "listener.hpp"
#include "pch/pch.hpp"

namespace dw {
    namespace net = boost::asio;
    using tcp = boost::asio::ip::tcp;

    void net_server::run(boost::asio::ip::address address, unsigned short port, int threads) {
        // The io_context is required for all I/O
        net::io_context ioc{threads};

        // Create and launch a listening port
        std::make_shared<listener>(ioc, tcp::endpoint{address, port})->run();

        // Run the I/O service on the requested number of threads
        std::vector<std::thread> v;
        v.reserve(threads - 1);
        for (auto i = threads - 1; i > 0; --i)
            v.emplace_back([&ioc] { ioc.run(); });
        ioc.run();
    }
}
