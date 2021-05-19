#include "TestFillArea.h"


TEST_F(TestFillArea, Given_canvas_not_exists_then_fillArea_cannot_be_drawn) {
    std::string request = "B 10 11";
    std::vector<std::string> requestItems = utils::split(request, ' ');
    EXPECT_FALSE(pFillArea->validateShapeConstraints(requestItems));
}

TEST_F(TestFillArea, when_drawfill_requested_then_its_contraint_respected) {
    std::string request = "C 20 4";
    m_processor.processRequest(request);
    request = "B 22 1";
    EXPECT_FALSE(m_processor.processRequest(request));
}

TEST_F(TestFillArea, when_drawfill_outside_canvas_requested_then_its_contraint_respected) {
    std::string request = "C 20 4";
    m_processor.processRequest(request);
    request = "B 25 1 c";
    EXPECT_FALSE(m_processor.processRequest(request));
}

