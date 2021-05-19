#pragma once

#include <gtest/gtest.h>
#include "../../main/shape/IShape.h"
#include "../../main/processor/IProcessor.h"


class TestCanvas : public ::testing::Test {
public:
    IShape *pCanvas;
    IProcessor m_processor;
    ICanvasPage *pICanvasPage;

    void SetUp() override {

    }

    void TearDown() override {
        ICanvasPage::resetInstance();
    }
};




