#pragma once

#include "../IShape.h"
#include "Line.h"

class Rectangle : public IShape {

    IShapeAttributes shapeAttributes{
            .description = "Should create a new rectangle, whose upper left corner is (x1,y1) and lower right corner is "
                           "(x2,y2). Horizontal and vertical lines will be drawn using the ",
            .menuSelector = "R",
            .commandParameters = "x1 y1 x2 y2",
            .enable = true};

    const int EXPECTED_ACTUAL_ARGUMENT = 5;

    Line line;

    ICanvasPage *pICanvasPage;
    
    std::vector<std::vector<std::string>> lineDrawRequests;
public:

    IShapeAttributes &getAttributes() override { return shapeAttributes; };

    bool validateCommand(std::vector<std::string> &requestItems) override;

    CanvasPage getBuildCanvas(std::vector<std::string> &requestItems) override;

    bool validateShapeConstraints(std::vector<std::string> &requestItems) override;

    void setPoints(std::vector<std::string> &requestItems);
};




