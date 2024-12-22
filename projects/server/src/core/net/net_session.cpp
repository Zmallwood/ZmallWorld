#include "net_session.hpp"
#include "boost/beast/core/flat_buffer.hpp"
#include "boost/beast/core/multi_buffer.hpp"
#include "pch/pch.hpp"
#include "core/session/session_loop.hpp"

namespace forr {
    namespace beast = boost::beast;
    namespace http = beast::http;
    namespace websocket = beast::websocket;
    using tcp = boost::asio::ip::tcp;

    // Take ownership of the socket
    net_session::net_session(tcp::socket &&socket) : ws_(std::move(socket)) {
    }

    // Start the asynchronous operation
    void net_session::run() {
        // Set suggested timeout settings for the websocket
        ws_.set_option(websocket::stream_base::timeout::suggested(beast::role_type::server));

        // Set a decorator to change the Server of the handshake
        ws_.set_option(websocket::stream_base::decorator([](websocket::response_type &res) {
            res.set(http::field::server, std::string(BOOST_BEAST_VERSION_STRING) + " websocket-server-async");
        }));

        // Accept the websocket handshake
        ws_.async_accept(beast::bind_front_handler(&net_session::on_accept, shared_from_this()));
    }

    void net_session::on_accept(beast::error_code ec) {
        if (ec)
            return fail(ec, "accept");

        session_loop_ = std::make_shared<session_loop>(shared_from_this());
        session_loop_->march();
        //do_read();
    }

    void net_session::do_read() {
        // Read a message into our buffer
        ws_.async_read(buffer_, beast::bind_front_handler(&net_session::on_read, shared_from_this()));
    }

    void net_session::on_read(beast::error_code ec, std::size_t bytes_transferred) {
        boost::ignore_unused(bytes_transferred);

        // This indicates that the session was closed
        if (ec == websocket::error::closed)
            return;

        if (ec)
            fail(ec, "read");

        std::string s(boost::asio::buffer_cast<const char *>(buffer_.data()), buffer_.size());
        std::cout << "Messages recieved: " << s << std::endl;
        session_loop_->march();
        //do_write("tjoho");
    }

    void net_session::do_write(std::string_view message) {

        boost::beast::flat_buffer b;
        boost::beast::ostream(b) << message;

        // Echo the message
        ws_.text(ws_.got_text());
        ws_.async_write(b.data(), beast::bind_front_handler(&net_session::on_write, shared_from_this()));
    }

    void net_session::on_write(beast::error_code ec, std::size_t bytes_transferred) {
        boost::ignore_unused(bytes_transferred);

        if (ec)
            return fail(ec, "write");

        // Clear the buffer
        buffer_.consume(buffer_.size());

        session_loop_->march();
        //do_read();
    }
}
