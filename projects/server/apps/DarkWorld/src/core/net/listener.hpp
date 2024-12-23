// Copright 2024 Andreas Åkerberg

#pragma once

namespace forr {
    class listener : public std::enable_shared_from_this<listener> {
      public:
        listener(boost::asio::io_context &ioc, boost::asio::ip::tcp::endpoint endpoint);
        void run();

      private:
        void do_accept();
        void on_accept(boost::beast::error_code ec, boost::asio::ip::tcp::socket socket);

        boost::asio::io_context &ioc_;
        boost::asio::ip::tcp::acceptor acceptor_;
    };
}
