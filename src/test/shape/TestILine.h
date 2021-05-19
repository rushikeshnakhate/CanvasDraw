#pragma once

#include <gtest/gtest.h>
#include "../../main/shape/IShape.h"
#include "../../main/shape/impl/Line.h"
#include "../../main/processor//IProcessor.h"

class TestILine : public ::testing::Test {
public:
    IShape *pLine;
    ICanvasPage *pICanvasPage;
    IProcessor m_processor;

    void SetUp() override {
        pLine = new Line();

    }

    void TearDown() override {
        pICanvasPage->resetInstance();
        delete pLine;
    }
};




