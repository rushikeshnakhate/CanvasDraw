#include "../ICanvasPage.h"

ICanvasPage *ICanvasPage::pCanvasPage = nullptr;

void ICanvasPage::publishCanvas(CanvasPage canvasPage) {
    this->globalCanvas = canvasPage;
    publishCanvasDimension(canvasPage);
}

ICanvasPage *ICanvasPage::getInstance() {
    if (pCanvasPage == nullptr)
        pCanvasPage = new ICanvasPage();
    return pCanvasPage;
}

bool ICanvasPage::isCanvasExists() {
    return (globalCanvas.empty());
}

void ICanvasPage::paint(CanvasPage &page) {
    for (auto height = 0; height < page.size(); height++) {
        for (auto width = 0; width < page[height].size(); width++) {
            std::cout << page[height][width];
        }
        std::cout << std::endl;
    }
}

void ICanvasPage::resetInstance() {
    delete pCanvasPage;
    pCanvasPage = nullptr;
}

void ICanvasPage::publishCanvasDimension(CanvasPage &canvasPage) {
    this->canvasWidthHeight.first = canvasPage[0].size();
    this->canvasWidthHeight.second = canvasPage.size();
}


