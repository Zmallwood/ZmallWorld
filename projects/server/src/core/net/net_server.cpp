#include "pch/pch.hpp"
#include "net_server.hpp"
#include "session.hpp"

namespace forr {
    namespace beast = boost::beast;         // from <boost/beast.hpp>
    namespace net = boost::asio;            // from <boost/asio.hpp>
    using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>



    // Accepts incoming connections and launches the sessions
    class listener : public std::enable_shared_from_this<listener> {
        net::io_context &ioc_;
        tcp::acceptor acceptor_;

      public:
        listener(net::io_context &ioc, tcp::endpoint endpoint) : ioc_(ioc), acceptor_(ioc) {
            beast::error_code ec;

            // Open the acceptor
            acceptor_.open(endpoint.protocol(), ec);
            if (ec) {
                fail(ec, "open");
                return;
            }

            // Allow address reuse
            acceptor_.set_option(net::socket_base::reuse_address(true), ec);
            if (ec) {
                fail(ec, "set_option");
                return;
            }

            // Bind to the server address
            acceptor_.bind(endpoint, ec);
            if (ec) {
                fail(ec, "bind");
                return;
            }

            // Start listening for connections
            acceptor_.listen(net::socket_base::max_listen_connections, ec);
            if (ec) {
                fail(ec, "listen");
                return;
            }
        }

        // Start accepting incoming connections
        void run() {
            do_accept();
        }

      private:
        void do_accept() {
            // The new connection gets its own strand
            acceptor_.async_accept(net::make_strand(ioc_),
                                   beast::bind_front_handler(&listener::on_accept, shared_from_this()));
        }

        void on_accept(beast::error_code ec, tcp::socket socket) {
            if (ec) {
                fail(ec, "accept");
            } else {
                // Create the session and run it
                std::make_shared<session>(std::move(socket))->run();
            }

            // Accept another connection
            do_accept();
        }
    };

    //------------------------------------------------------------------------------

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
