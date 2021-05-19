#pragma once

#include<vector>
#include "../shape/IShape.h"
#include "../processor/IProcessor.h"

class IMenu {

    IProcessor m_processor;
    std::vector<IShape *> m_menuItems;
public:
    ~IMenu() {
        for (auto &item : m_menuItems) {
            delete item;
        }
    }

    std::string show();

    void addToMenu(IShape *item);

    void selectMenu();

    std::vector<IShape *> getMenuItems() { return m_menuItems; }

};




