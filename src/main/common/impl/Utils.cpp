#include "../Utils.h"
#include<sstream>
#include <iostream>

namespace utils {
    std::vector<std::string> split(const std::string &str, char delimiter) {
        std::vector<std::string> result;
        std::stringstream ss{str};
        std::string item;
        while (getline(ss, item, delimiter)) {
            result.push_back(item);
        }
        return result;
    }

    std::string extractToString(int argc, char **argv) {
        std::string str;
        for (int start = 1; start < argc; start++) {
            str = str + argv[start];
        }
        return str;
    }

    signed int to_int(std::string &input) {
        return std::stoi(input);
    }
}