#pragma once

#include <fcntl.h>
#include <unistd.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <csignal>
#include <ctime>
#include <map>
#include <memory>
#include <string>
#include <thread>


namespace util {
    std::string dir_name(std::string const& path);
    std::string readlink(const std::string& path);
}
