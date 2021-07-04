#include "util.h"
#include <cstring>
#include <sstream>

namespace util {

    std::string dir_name(std::string const &path) {
        size_t pos = path.find_last_of("/");
        if (pos == std::string::npos) return "";
        return path.substr(0, pos);
    }
    std::string readlink(const std::string &path) {
        char buff[4096];
        ssize_t len = ::readlink(path.c_str(), buff, sizeof(buff)-1);
        if (len != -1) {
            buff[len] = '\0';
            return std::string(buff);
        }
        return "";
    }

}  // namespace util
