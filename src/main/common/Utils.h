#pragma once

#include <string>
#include <vector>

namespace utils {
    std::vector<std::string> split(const std::string &str, char delimiter);

    std::string extractToString(int argc, char **argv);

    int to_int(std::string &input);
};




