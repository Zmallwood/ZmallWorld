// Copright 2024 Andreas Åkerberg

#pragma once

namespace zw
{
class server
{
  public:
    void run(boost::asio::ip::address address, unsigned short port, int threads);
};
} // namespace zw
