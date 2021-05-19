//
// Created by ayush on 5/18/2021.
//

#include "TestAppl.h"

TEST_F(TestAppl, running_all_input_cases) {
    std::string request = "C 20 4";
    m_processor.processRequest(request);

    request = "L 1 2 6 2";
    m_processor.processRequest(request);

    request = "L 6 3 6 4";
    m_processor.processRequest(request);

    request = "R 14 1 18 3";
    m_processor.processRequest(request);

    request = "B 10 3 o";
    m_processor.processRequest(request);

    request = "Q";
    m_processor.processRequest(request);
}