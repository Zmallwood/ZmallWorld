#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>

#include "common/singleton.hpp"
#include "common/utilities.hpp"
