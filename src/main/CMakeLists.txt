cmake_minimum_required(VERSION 3.15)
project(CanvasMain)
set(CMAKE_CXX_STANDARD 17)
set(HEADER client/IApplication.h
        menu/IMenu.h
        common/Utils.h
        shape/IShape.h
        shape/impl/Canvas.h
        shape/impl/FillArea.h
        shape/impl/IAttributes.h
        shape/impl/Line.h
        shape/impl/Rectangle.h)
set(SRC menu/impl/IMenu.cpp
        processor/impl/IProcessor.cpp
        shape/impl/Canvas.cpp
        shape/impl/Line.cpp
        shape/impl/FillArea.cpp
        shape/impl/Rectangle.cpp
        common/impl/Utils.cpp
        Main.cpp
        canvaspage/impl/ICanvasPage.cpp)
include_directories(client)
add_executable(CanvasMain ${SRC} ${HEADER})
#add_library(CanvasMain ${SRC} ${HEADER})