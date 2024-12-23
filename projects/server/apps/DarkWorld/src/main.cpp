// Copyright 2024 Andreas Åkerberg

#include "core/server.hpp"

int main(int argc, char *argv[]) {
  std::cout << "DarkWorld\n";
  forr::server server;
  server.run();
  return EXIT_SUCCESS;
}
