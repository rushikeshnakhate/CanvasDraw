#pragma once

#include <gtest/gtest.h>
#include "../../main/shape/IShape.h"
#include "../../main/shape/impl/FillArea.h"
#include "../../main/processor//IProcessor.h"

class TestFillArea : public ::testing::Test {
public:
    IShape *pFillArea;
    IProcessor m_processor;

    void SetUp() override {
        pFillArea = new FillArea();
    }

    void TearDown() override {
        delete pFillArea;
    }
};




