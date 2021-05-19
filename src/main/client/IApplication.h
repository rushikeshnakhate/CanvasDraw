#pragma once

#include "../menu/IMenu.h"
#include "../shape/impl/Line.h"
#include "../shape/impl/Rectangle.h"
#include "../shape/impl/FillArea.h"
#include "../shape/impl/Canvas.h"
#include "../shape/impl/Quit.h"

class IApplication {
    IMenu *pMenu;
public:
    IApplication() {
        pMenu = new IMenu;
        pMenu->addToMenu(new Canvas);
        pMenu->addToMenu(new Line);
        pMenu->addToMenu(new Rectangle);
        pMenu->addToMenu(new FillArea);
        pMenu->addToMenu(new Quit);
        pMenu->show();
    }

    void selectMenu() {
        pMenu->selectMenu();
    }

    ~IApplication() {
        delete pMenu;
    }
};



