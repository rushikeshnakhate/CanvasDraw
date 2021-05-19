#include "TestIMenu.h"

TEST_F(TestIMenu, when_item_configured_then_its_added) {
    pMenu->addToMenu(new Canvas);
    std::vector<IShape *> items = pMenu->getMenuItems();
    std::string actualOutput{};
    for (auto x: items) {
        actualOutput = x->getAttributes().menuSelector;
    }
    std::string expected = "C";
    EXPECT_EQ(expected, actualOutput);
}