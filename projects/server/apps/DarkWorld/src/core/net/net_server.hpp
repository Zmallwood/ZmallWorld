// Copright 2024 Andreas Åkerberg

#pragma once

namespace forr {
    class net_server {
      public:
        void run(boost::asio::ip::address address, unsigned short port, int threads);
    };
}