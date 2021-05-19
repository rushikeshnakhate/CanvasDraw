#pragma once

#include "../IShape.h"
#include "../../common/Utils.h"

const char ROW_MARKER = '-';
const char COL_MARKER = '|';
//const char NO_DISPLAY_MARKER = ' ';

class Canvas : public IShape {

    IShapeAttributes shapeAttributes{.description = "Should create a new canvas CanvasPage of width w and height h.",
            .menuSelector = "C", .commandParameters = "w h", .enable = true};
    const int EXPECTED_ACTUAL_ARGUMENT = 3;
    const int MARGIN = 2;
    signed int widthAsColumns{0};
    signed int heightAsRows{0};
public:

    IShapeAttributes &getAttributes() override { return shapeAttributes; }

    bool validateCommand(std::vector<std::string> &requestItems) override;

    CanvasPage getBuildCanvas(std::vector<std::string> &requestItems) override;

    CanvasPage buildOnCanvas() const;

    bool validateShapeConstraints(std::vector<std::string> &requestItems) override;


    void setWidthHeight(std::vector<std::string> &requestItem);
};




