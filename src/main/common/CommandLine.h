#pragma once
#define EXACT_COUNT_OF_PARAMETERS_EXPECTED 1

#include <stdexcept>
#include <string>
#include "../common/Utils.h"

class CommandLine {
public:
    static void parse(int argc, char **argv) {
        if (argc != EXACT_COUNT_OF_PARAMETERS_EXPECTED)
            throw std::runtime_error(
                    "Incorrect argument passed,Expected=" + std::to_string(EXACT_COUNT_OF_PARAMETERS_EXPECTED) +
                    ",actual passed=" + std::to_string(argc) + " arguments=" + utils::extractToString(argc, argv));
    }

};




