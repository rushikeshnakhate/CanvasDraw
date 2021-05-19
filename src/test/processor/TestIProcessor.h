#pragma once

#include <gtest/gtest.h>
#include "../src/main/processor/IProcessor.h"
#include <string>

class TestIProcessor : public ::testing::Test {
public:
    IProcessor m_processor;
    ICanvasPage *pICanvasPage;

    void SetUp() override {
        pICanvasPage->getInstance();
    }

    void TearDown() override {
        pICanvasPage->resetInstance();
    }
};




