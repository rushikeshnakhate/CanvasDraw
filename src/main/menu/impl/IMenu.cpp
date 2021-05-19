
#include "../IMenu.h"

std::string IMenu::show() {
    for (auto &item: m_menuItems) {
        std::cout << " '" << item->getAttributes().menuSelector << "' " << item->getAttributes().description
                  << std::endl;
    }
    return "";
}

void IMenu::addToMenu(IShape *item) {
    if (!item->getAttributes().enable)
        throw std::runtime_error("Error: Shape=" + item->getAttributes().menuSelector +
                                 " is marked as disabled,but it was attempted to add in console menu");
    m_menuItems.push_back(item);
}

void IMenu::selectMenu() {
    std::cout << "Your selection please." << std::endl;
    std::string input;
    getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Error:Incorrect argument passed,expected " << std::endl;
        std::cout << show() << ", actual received='" << input << "'" << std::endl;
        return;
    }
    m_processor.processRequest(input);
}
