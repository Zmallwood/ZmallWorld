#pragma once

namespace forr {

    // Echoes back all received WebSocket messages
    class session : public std::enable_shared_from_this<session> {
        boost::beast::websocket::stream<boost::beast::tcp_stream> ws_;
        boost::beast::flat_buffer buffer_;

      public:
        // Take ownership of the socket
        explicit session(boost::asio::ip::tcp::socket &&socket);

        // Start the asynchronous operation
        void run();
        void on_accept(boost::beast::error_code ec);
        void do_read();
        void on_read(boost::beast::error_code ec, std::size_t bytes_transferred);
        void on_write(boost::beast::error_code ec, std::size_t bytes_transferred);
    };
}
