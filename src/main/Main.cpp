#include <iostream>
#include "IApplication.h"
#include "common/CommandLine.h"
#include "common/Model.h"

int STATUS;

int main(int argc, char *argv[]) {
    STATUS = APPLICATION_STATUS::running;
    try {
        CommandLine::parse(argc, argv);
        IApplication newApp;
        while (STATUS == APPLICATION_STATUS::running) {
            newApp.selectMenu();
        }
    } catch (std::exception &e) {
        std::cout << "Application stopped with exception=" << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Application stopped with unknown exception=" << std::endl;
    }
    return 0;
}

