#pragma once

#include "../IShape.h"

using Point = std::pair<int, int>;

class Line : public IShape {
    IShapeAttributes shapeAttributes{.description = "Should create a new line from (x1,y1) to (x2,y2). "
                                                    "Currently only horizontal or vertical lines are supported. "
                                                    "Horizontal and vertical lines will be drawn using the 'x' character.",
            .menuSelector = "L", .commandParameters = "x1 y1 x2 y2", .enable = true};
    char drawChar = {'x'};
    const int EXPECTED_ACTUAL_ARGUMENT = 5;

    ICanvasPage *pICanvasPage;

    Point startPoint{};
    Point endPoint{};
public:

    IShapeAttributes &getAttributes() override { return shapeAttributes; }

    bool validateCommand(std::vector<std::string> &requestItems) override;

    CanvasPage getBuildCanvas(std::vector<std::string> &requestItems) override;

    void drawHorizontal(CanvasPage &page, int row, int col) const;

    void drawVertical(CanvasPage &page, int row, int col) const;

    void setPoints(std::vector<std::string> &requestItems);

    bool validateShapeConstraints(std::vector<std::string> &requestItems) override;

    bool validateDimensionWithinCanvas();
};
