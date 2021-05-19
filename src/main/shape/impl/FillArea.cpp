#include <queue>
#include <algorithm>
#include "FillArea.h"

bool FillArea::validateCommand(std::vector<std::string> &requestItems) {
    return (requestItems.size() == EXPECTED_ACTUAL_ARGUMENT);
}

bool FillArea::validateShapeConstraints(std::vector<std::string> &requestItems) {
    pICanvasPage = ICanvasPage::getInstance();
    if (pICanvasPage->isCanvasExists()) {
        std::cout << "canvas does not exits,please create canvas before creating Rectangle" << std::endl;
        return false;
    }
    setPoint(requestItems);
    return (validateDimensionWithinCanvas(requestItems));
}

CanvasPage FillArea::getBuildCanvas(std::vector<std::string> &requestItems) {
    CanvasPage canvas;
    try {
        setPoint(requestItems);
        canvas = pICanvasPage->getCanvasPage();
        buildOnCanvas(canvas);
        return canvas;
    }
    catch (std::exception &e) {
        std::cout << "Exception on getBuildCanvas=" << e.what() << std::endl;
    }
    return canvas;
}

void FillArea::buildOnCanvas(CanvasPage &canvas) {
    try {
        //X-Cord == width == col
        //Y-Cord = height = row
        //input X, Y
        Visitor visited = initVisitedNode(canvas);
        std::queue<Point> inspector;
        inspector.push({this->xyDimensions.first, this->xyDimensions.second});
        while (!inspector.empty()) {
            //extract front pair
            int column = inspector.front().first;
            int row = inspector.front().second;
            inspector.pop();
            std::vector<Point> neighbours{{row,     column},
                                          {row + 1, column},
                                          {row - 1, column},
                                          {row,     column + 1},
                                          {row,     column - 1}};

            ColourFiller(canvas, visited, inspector, neighbours);
        }
    }
    catch (std::exception &e) {
        std::cout << "exception caught on building fillArea, exception=" << e.what() << std::endl;
    }
}

void FillArea::ColourFiller(CanvasPage &canvas,
                            Visitor &visited, std::queue<Point> &obj,
                            std::vector<Point> &neighbours) {
    for (auto neighbour : neighbours) {
        if (!isCoordinateOutSideCanvas(neighbour.first, neighbour.second)
            && (visited[neighbour.first][neighbour.second] == NOT_VISITED)
            && (canvas[neighbour.first][neighbour.second] == NO_DISPLAY_MARKER)) {
            obj.push({neighbour.second, neighbour.first});
            visited[neighbour.first][neighbour.second] = VISITED;
            canvas[neighbour.first][neighbour.second] = fillChar;
        }
    }
}

bool FillArea::validateDimensionWithinCanvas(std::vector<std::string> &requestItems) {
    if ((this->xyDimensions.first < 0) ||
        (this->xyDimensions.second > pICanvasPage->getCanvasDimension().second) ||
        (this->xyDimensions.first > pICanvasPage->getCanvasDimension().first)) {
        std::cout << "Error:Dimension requested are outside canvas area,expected canvas width="
                  << pICanvasPage->getCanvasDimension().first << " canvas height="
                  << pICanvasPage->getCanvasDimension().second
                  << " actual received width=" << this->xyDimensions.first << " height="
                  << this->xyDimensions.second
                  << std::endl;
        return false;
    }
    return true;
}


void FillArea::setPoint(std::vector<std::string> &requestItems) {
    try {
        if (requestItems.size() == EXPECTED_ACTUAL_ARGUMENT) {
            this->xyDimensions.first = utils::to_int(requestItems[1]);
            this->xyDimensions.second = utils::to_int(requestItems[2]);
            this->fillChar = requestItems[3][0];
        }
    } catch (std::exception &e) {
        std::cout << "Error: exception in setPoint exception=[" << e.what() << "]" << std::endl;
    }
}

Visitor FillArea::initVisitedNode(CanvasPage &page) {
    Visitor visited;
    for (auto row = 0; row < page.size(); row++) {
        std::vector<int> canvasRow;
        canvasRow.reserve(page[0].size());
        for (auto col = 0; col < page[0].size(); col++) {
            canvasRow.push_back(VISITOR::NOT_VISITED);
        }
        visited.push_back(canvasRow);
    }
    return visited;
}

bool FillArea::isCoordinateOutSideCanvas(int row, int column) {
    return (row < 0 || column < 0 ||
            (column >= pICanvasPage->getCanvasDimension().first) ||
            (row >= pICanvasPage->getCanvasDimension().second));
}
