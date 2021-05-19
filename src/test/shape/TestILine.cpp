#include "TestILine.h"

TEST_F(TestILine, Given_canvas_not_exists_then_line_cannot_be_drawn) {
    pICanvasPage = pICanvasPage->getInstance();
    std::string request = "B 10 11";
    std::vector<std::string> requestItems = utils::split(request, ' ');
    EXPECT_FALSE(pLine->validateShapeConstraints(requestItems));
}

TEST_F(TestILine, when_drawLine_outside_width_then_contraint_validated) {
    std::string request = "C 20 4";
    m_processor.processRequest(request);
    request = "B 22 1";
    EXPECT_FALSE(m_processor.processRequest(request));
}

TEST_F(TestILine, when_drawLine_outside_height_then_contraint_validated) {
    std::string request = "C 20 4";
    m_processor.processRequest(request);
    request = "B 20 1";
    EXPECT_FALSE(m_processor.processRequest(request));
}
