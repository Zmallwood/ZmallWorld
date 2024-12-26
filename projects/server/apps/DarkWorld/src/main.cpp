// Copyright 2024 Andreas Åkerberg

#include "core/server.hpp"

int main(int argc, char *argv[])
{
    dw::get_singleton<dw::server>().run();
    return EXIT_SUCCESS;
}
