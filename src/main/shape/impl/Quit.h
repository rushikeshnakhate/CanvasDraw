#pragma once

#include "../IShape.h"
#include "../../common/Utils.h"

class Quit : public IShape {

    IShapeAttributes shapeAttributes{.description = "Should quit the program.", .menuSelector = "Q", .commandParameters = "", .enable = true};
public:

    IShapeAttributes &getAttributes() override { return shapeAttributes; }

    bool validateCommand(std::vector<std::string> &requestItems) override { return true; };

    CanvasPage getBuildCanvas(std::vector<std::string> &requestItems) override { return CanvasPage(); };

    bool validateShapeConstraints(std::vector<std::string> &requestItems) override { return true; };

};




