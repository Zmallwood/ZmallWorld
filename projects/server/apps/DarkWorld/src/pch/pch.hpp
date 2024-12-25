// Copyright 2024 Andreas Åkerberg

#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <queue>
#include <map>
#include <set>
#include <chrono>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/strand.hpp>

#include "common/singleton.hpp"
#include "common/key_codes.hpp"
#include "common/utilities.hpp"
#include "common/hash.hpp"
#include "common/matter/size.hpp"
#include "common/matter/sizef.hpp"
#include "common/matter/point.hpp"
#include "common/matter/pointf.hpp"
#include "common/time.hpp"
#include "common/canvas_utilities.hpp"
#include "common/graphics/draw.hpp"
