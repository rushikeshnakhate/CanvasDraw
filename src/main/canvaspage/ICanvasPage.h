#pragma once

#include <vector>
#include <iostream>

using CanvasPage = std::vector<std::vector<char>>;


class ICanvasPage {

    static ICanvasPage *pCanvasPage;

    CanvasPage globalCanvas{};

    ICanvasPage() = default;

    ICanvasPage(const ICanvasPage &canvasPage) = delete;

    ICanvasPage &operator=(const ICanvasPage &canvasPage) = delete;

    std::pair<int, int> canvasWidthHeight{0, 0};
public:
    ~ICanvasPage() {};

    void publishCanvas(CanvasPage canvasPage);

    static ICanvasPage *getInstance();

    bool isCanvasExists();

    void paint(CanvasPage &page);

    CanvasPage getCanvasPage() { return globalCanvas; }

    static void resetInstance();

    std::pair<int, int> getCanvasDimension() { return canvasWidthHeight; };

    void publishCanvasDimension(CanvasPage &canvasPage);
};




