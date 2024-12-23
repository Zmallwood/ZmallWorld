// Copyright 2024 Andreas Åkerberg

#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <queue>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>

#include "common/singleton.hpp"
#include "common/key_codes.hpp"
#include "common/utilities.hpp"
