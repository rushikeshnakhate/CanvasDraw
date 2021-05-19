
#include "TestIProcessor.h"

TEST_F (TestIProcessor, when_correct_option_choosen_then_its_accepted) {
    std::string input = "C 2 1";
    EXPECT_TRUE(m_processor.processRequest(input));
}

TEST_F (TestIProcessor, when_incorrect_shape_choosen_then_its_reported) {
    std::string input = "INCORRECT 10 11";
    EXPECT_FALSE(m_processor.processRequest(input));
}