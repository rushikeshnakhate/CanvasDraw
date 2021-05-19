#pragma once

#include <gtest/gtest.h>
#include "../../main/menu/IMenu.h"

class TestIMenu : public ::testing::Test {
public:
    IMenu *pMenu;

    void SetUp() override {
        pMenu = new IMenu;
    }

    void TearDown() override {
        delete pMenu;
    }
};




