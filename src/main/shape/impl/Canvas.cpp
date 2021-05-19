
#include "Canvas.h"


CanvasPage Canvas::getBuildCanvas(std::vector<std::string> &requestItems) {
    try {
        setWidthHeight(requestItems);
        return buildOnCanvas();
    }
    catch (std::exception &e) {
        std::cout << "Exception on getBuildCanvas=" << e.what() << std::endl;
    }
    return CanvasPage();
}

void Canvas::setWidthHeight(std::vector<std::string> &requestItems) {
    this->widthAsColumns = std::stoi(requestItems[1]);
    this->heightAsRows = std::stoi(requestItems[2]);
}

bool Canvas::validateCommand(std::vector<std::string> &requestItems) {
    return (requestItems.size() == EXPECTED_ACTUAL_ARGUMENT);
}

CanvasPage Canvas::buildOnCanvas() const {
    CanvasPage canvasPage_;
    for (auto row = 0; row < (this->heightAsRows + MARGIN); row++) {
        std::vector<char> pageElement;
        for (auto col = 0; col < (this->widthAsColumns + MARGIN); col++) {
            if (row == 0 || row == (this->heightAsRows - 1 + MARGIN))
                pageElement.push_back(ROW_MARKER);
            else if (col == 0 || col == (this->widthAsColumns - 1 + MARGIN))
                pageElement.push_back(COL_MARKER);
            else
                pageElement.push_back(NO_DISPLAY_MARKER);

        }
        canvasPage_.push_back(pageElement);
    }
    return canvasPage_;
}

bool Canvas::validateShapeConstraints(std::vector<std::string> &requestItems) {
    setWidthHeight(requestItems);
    if (this->widthAsColumns < 0 || this->heightAsRows < 0) {
        std::cout << "Canvas width or height cannot be negative received height=" << this->heightAsRows << " width="
                  << this->widthAsColumns << std::endl;
        return false;
    }
    return true;
}
