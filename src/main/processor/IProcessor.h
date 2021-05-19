#pragma once

#include<string>
#include "../common/Utils.h"
#include "../shape/IShape.h"
#include "../shape/impl/Rectangle.h"
#include "../shape/impl/Line.h"
#include "../shape/impl/FillArea.h"
#include "../shape/impl/Canvas.h"

class IProcessor {
public:
    static bool processRequest(const std::string &request);

    static IShape *getInstance(std::basic_string<char> &request);

    static bool isAppStopRequested(std::basic_string<char> &request);
};




