// Copright 2024 Andreas Åkerberg

#pragma once

namespace forr {

    class engine;
    // Echoes back all received WebSocket messages
    class net_session : public std::enable_shared_from_this<net_session> {
      public:
        // Take ownership of the socket
        explicit net_session(boost::asio::ip::tcp::socket &&socket);

        // Start the asynchronous operation
        void run();
        void on_accept(boost::beast::error_code ec);
        void add_message(std::string_view message);
        void do_read();
        std::string get_last_message();
        void do_write();
        void on_read(boost::beast::error_code ec, std::size_t bytes_transferred);
        void on_write(boost::beast::error_code ec, std::size_t bytes_transferred);

      private:
        boost::beast::websocket::stream<boost::beast::tcp_stream> ws_;
        boost::beast::flat_buffer read_buffer_;
        boost::beast::flat_buffer write_buffer_;
        std::shared_ptr<engine> engine_;
        std::queue<std::string> outgoing_messages_;
        bool is_writing_ {false};
        std::string last_message_;
    };
}
