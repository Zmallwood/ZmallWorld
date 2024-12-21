#include "pch/pch.hpp"
#include "core/server.hpp"

int main(int argc, char *argv[]) {
    // Check command line arguments.
    if (argc != 4) {
        std::cerr << "Usage: websocket-server-async <address> <port> <threads>\n"
                  << "Example:\n"
                  << "    websocket-server-async 0.0.0.0 8080 1\n";
        return EXIT_FAILURE;
    }

    auto const address = boost::beast::net::ip::make_address(argv[1]);
    auto const port = static_cast<unsigned short>(std::atoi(argv[2]));
    auto const threads = std::max<int>(1, std::atoi(argv[3]));

    forr::server server;
    server.run(address, port, threads);

    return EXIT_SUCCESS;
}
