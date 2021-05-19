#pragma once


#include <gtest/gtest.h>
#include <main/processor/IProcessor.h>
#include <main/canvaspage/ICanvasPage.h>


class TestAppl : public ::testing::Test {
public:
    IProcessor m_processor;
    ICanvasPage *pICanvasPage;

    void SetUp() override {

    }

    void TearDown() override {
        ICanvasPage::resetInstance();
    }
};




