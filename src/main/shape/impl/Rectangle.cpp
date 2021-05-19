#include "Rectangle.h"

bool Rectangle::validateCommand(std::vector<std::string> &requestItems) {
    return (requestItems.size() == EXPECTED_ACTUAL_ARGUMENT);
}

bool Rectangle::validateShapeConstraints(std::vector<std::string> &requestItems) {
    pICanvasPage = ICanvasPage::getInstance();
    if (pICanvasPage->isCanvasExists()) {
        std::cout << "canvas does not exits,please create canvas before creating Rectangle" << std::endl;
        return false;
    }
    return true;
}

CanvasPage Rectangle::getBuildCanvas(std::vector<std::string> &requestItems) {
    CanvasPage canvas;
    try {

        setPoints(requestItems);
        for (auto lineDrawRequest : lineDrawRequests) {
            canvas = line.getBuildCanvas(lineDrawRequest);
            pICanvasPage = ICanvasPage::getInstance();
            pICanvasPage->publishCanvas(canvas);
        }
        return canvas;
    } catch (std::exception &e) {
        std::cout << "Exception on getBuildCanvas=" << e.what() << std::endl;
    }
    return canvas;
}

void Rectangle::setPoints(std::vector<std::string> &requestItems) {
    std::vector<std::string> firstHorizontalLine{"L", requestItems[1], requestItems[2], requestItems[3],
                                                 requestItems[2]};
    lineDrawRequests.push_back(firstHorizontalLine);

    std::vector<std::string> secondHorizontalLine{"L", requestItems[1], requestItems[4], requestItems[3],
                                                  requestItems[4]};
    lineDrawRequests.push_back(secondHorizontalLine);
    std::vector<std::string> firstVerticalLine{"L", requestItems[1], requestItems[2], requestItems[1],
                                               requestItems[4]};
    lineDrawRequests.push_back(firstVerticalLine);
    std::vector<std::string> secondVerticalLine{"L", requestItems[3], requestItems[2], requestItems[3],
                                                requestItems[4]};


    lineDrawRequests.push_back(secondVerticalLine);
}

