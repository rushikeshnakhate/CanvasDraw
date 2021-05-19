#include "TestCanvas.h"

TEST_F(TestCanvas, when_negative_values_are_passed_canvas_not_created) {
    std::string request = "C -20 4";
    m_processor.processRequest(request);
    request = "B 22 1";
    EXPECT_FALSE(m_processor.processRequest(request));
}
