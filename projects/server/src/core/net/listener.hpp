#pragma once

namespace forr {
    // Accepts incoming connections and launches the sessions
    class listener : public std::enable_shared_from_this<listener> {
        boost::asio::io_context &ioc_;
        boost::asio::ip::tcp::acceptor acceptor_;

      public:
        listener(boost::asio::io_context &ioc, boost::asio::ip::tcp::endpoint endpoint);
        // Start accepting incoming connections
        void run();

      private:
        void do_accept();
        void on_accept(boost::beast::error_code ec, boost::asio::ip::tcp::socket socket);
    };
}
