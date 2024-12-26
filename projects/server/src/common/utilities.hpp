// Copright 2024 Andreas Åkerberg

#pragma once

namespace zw
{
void fail(boost::beast::error_code ec, char const *what);
std::vector<std::string_view> split(const std::string_view str, const char delim);
} // namespace zw
