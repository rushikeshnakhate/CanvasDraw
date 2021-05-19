#include "Line.h"

bool Line::validateCommand(std::vector<std::string> &requestItems) {
    return (requestItems.size() == EXPECTED_ACTUAL_ARGUMENT);
}

bool Line::validateShapeConstraints(std::vector<std::string> &requestItems) {
    setPoints(requestItems);
    pICanvasPage = ICanvasPage::getInstance();
    if (pICanvasPage->isCanvasExists()) {
        std::cout << "canvas does not exits,please create canvas before creating Line" << std::endl;
        return false;
    }
    return (validateDimensionWithinCanvas());

}

bool Line::validateDimensionWithinCanvas() {
    if (this->startPoint.first > pICanvasPage->getCanvasDimension().first ||
        this->endPoint.first > pICanvasPage->getCanvasDimension().first ||
        this->startPoint.second > pICanvasPage->getCanvasDimension().second ||
        this->endPoint.second > pICanvasPage->getCanvasDimension().second) {
        std::cout << "Error:Dimension requested are outside canvas area,expected width="
                  << pICanvasPage->getCanvasDimension().first << " height=" << pICanvasPage->getCanvasDimension().second
                  << " actual received start point=" << startPoint.first << " " << startPoint.second << " end point="
                  << endPoint.second << " " << endPoint.second << std::endl;
        return false;
    }
    return true;
}


CanvasPage Line::getBuildCanvas(std::vector<std::string> &requestItems) {
    try {
        setPoints(requestItems);
        pICanvasPage = ICanvasPage::getInstance();
        CanvasPage canvasPage_ = pICanvasPage->getCanvasPage();
        for (auto row = 1; row <= canvasPage_.size(); row++) {
            for (auto col = 1; col <= canvasPage_[0].size(); col++) {
                drawHorizontal(canvasPage_, row, col);
                drawVertical(canvasPage_, row, col);
            }
        }
        return canvasPage_;
    } catch (std::exception &e) {
        std::cout << "Exception on getBuildCanvas=" << e.what() << std::endl;
    }
    return CanvasPage();
}


void Line::drawHorizontal(CanvasPage &page, int row, int col) const {
    if ((startPoint.first != endPoint.first) && (startPoint.second == endPoint.second) &&
        (startPoint.second == row)) {
        if (col >= startPoint.first && col <= endPoint.first) {
            page[row][col] = drawChar;
        }
    }
}

void Line::drawVertical(CanvasPage &page, int row, int col) const {
    if ((startPoint.first == endPoint.first) && (startPoint.second != endPoint.second) &&
        (startPoint.first == col)) {
        if (row >= startPoint.second && row <= endPoint.second) {
            page[row][col] = drawChar;
        }
    }
}

void Line::setPoints(std::vector<std::string> &requestItems) {
    if (requestItems.size() == EXPECTED_ACTUAL_ARGUMENT) {
        startPoint.first = utils::to_int(requestItems[1]);
        startPoint.second = utils::to_int(requestItems[2]);
        endPoint.first = utils::to_int(requestItems[3]);
        endPoint.second = utils::to_int(requestItems[4]);
    }
}




