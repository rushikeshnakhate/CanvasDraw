#pragma once

#include <queue>
#include "../IShape.h"

using Point = std::pair<int, int>;
using Visitor = std::vector<std::vector<int>>;

class FillArea : public IShape {
    IShapeAttributes shapeAttributes{.description = "Should fill the entire area connected to (x,y) with colour c. "
                                                    "The behavior of this is the same as that of the bucket fill "
                                                    "tool in getBuildCanvas  programs.",
            .menuSelector = "B", .commandParameters = "x y c", .enable = true};

    const int EXPECTED_ACTUAL_ARGUMENT = 4;

    ICanvasPage *pICanvasPage;

    Point xyDimensions{0, 0};

    char fillChar{'o'};

    enum VISITOR {
        VISITED,
        NOT_VISITED
    };


public:
    IShapeAttributes &getAttributes() override { return shapeAttributes; }

    bool validateCommand(std::vector<std::string> &requestItems) override;

    CanvasPage getBuildCanvas(std::vector<std::string> &requestItems) override;

    bool validateShapeConstraints(std::vector<std::string> &requestItems) override;

    bool validateDimensionWithinCanvas(std::vector<std::string> &requestItems);

    void setPoint(std::vector<std::string> &requestItems);

    void buildOnCanvas(CanvasPage &canvas);

    static Visitor initVisitedNode(CanvasPage &page);

    bool isCoordinateOutSideCanvas(int row, int column);

    void ColourFiller(CanvasPage &canvas,
                      Visitor &visited, std::queue<Point> &obj,
                      std::vector<Point> &neighbours);
};



