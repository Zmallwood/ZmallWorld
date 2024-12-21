#pragma once

namespace forr {
    class server {
      public:
        void run(boost::asio::ip::address address, unsigned short port, int threads);
    };
}
