#include "../IProcessor.h"

char REQUEST_DELIMITER = ' ';
extern int STATUS;

bool IProcessor::processRequest(const std::string &request) {
    std::vector<std::string> requestItems = utils::split(request, REQUEST_DELIMITER);
    try {
        if (!requestItems.empty()) {
            if (isAppStopRequested(requestItems[0])) return true;
            IShape *pShape = getInstance(requestItems[0]);
            if (pShape == nullptr) {
                std::cout << "Incorrect option"
                             " passed='" << requestItems[0] << "',Please check menu options and try again"
                          << std::endl;
                return false;
            }
            if (!pShape->validateCommand(requestItems)) {
                std::cout << "Incorrect argument passed,expected=" << pShape->getAttributes().menuSelector << " "
                          << pShape->getAttributes().commandParameters
                          << ",actual received='";
                for (const auto &x: requestItems) {
                    std::cout << x << " ";
                }
                std::cout << "'" << std::endl;
                return false;
            }
            if (!pShape->validateShapeConstraints(requestItems)) return false;

            ICanvasPage *pCanvasPage = ICanvasPage::getInstance();
            CanvasPage canvas = pShape->getBuildCanvas(requestItems);
            pCanvasPage->publishCanvas(canvas);
            pCanvasPage->paint(canvas);
            return true;
        }
        return false;

    } catch (std::exception &e) {
        std::cout << "Error:Exception in processRequest=" << e.what() << std::endl;
    }
    return false;
}

IShape *IProcessor::getInstance(std::basic_string<char> &request) {
    if (request == "C")
        return new Canvas;
    if (request == "L")
        return new Line;
    if (request == "B")
        return new FillArea;
    if (request == "R")
        return new Rectangle;
    std::cout << "Error:Incorrect Option provided,received=" << request
              << ",please check menu and try with correct option" << std::endl;
    return nullptr;
}

bool IProcessor::isAppStopRequested(std::basic_string<char> &request) {
    if (request == "Q") {
        STATUS = APPLICATION_STATUS::stopped;
        std::cout << "Application Quit request is received , App would stop now" << std::endl;
        return true;
    }
    return false;
}
