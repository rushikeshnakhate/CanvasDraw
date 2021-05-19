cmake_minimum_required(VERSION 3.15)
project(CanvasTest)
set(CMAKE_CXX_STANDARD 17)
include_directories(../../thirdparty/googletest/include)
include_directories(../../src)
set(HEADER ../main/client/IApplication.h
        ../main/menu/IMenu.h
        ../main/common/Utils.h
        ../main/shape/IShape.h
        ../main/shape/impl/Canvas.h
        ../main/shape/impl/FillArea.h
        ../main/shape/impl/IAttributes.h
        ../main/shape/impl/Line.h
        ../main/shape/impl/Rectangle.h
        menu/TestIMenu.h
        processor/TestIProcessor.h
        shape/TestILine.h
        shape/TestFillArea.h
        shape/TestCanvas.h
        feature/tdd/TestAppl.h)

set(SRC mainTest.cpp
        menu/TestIMenu.cpp
        processor/TestIProcessor.cpp
        shape/TestILine.cpp
        shape/TestFillArea.cpp
        shape/TestCanvas.cpp
        feature/tdd/TestAppl.cpp
        ../main/menu/impl/IMenu.cpp
        ../main/processor/impl/IProcessor.cpp
        ../main/shape/impl/Canvas.cpp
        ../main/shape/impl/Line.cpp
        ../main/shape/impl/FillArea.cpp
        ../main/shape/impl/Rectangle.cpp
        ../main/common/impl/Utils.cpp
        ../main/canvaspage/impl/ICanvasPage.cpp)
add_executable(CanvasTest ${SRC} ${HEADER})
target_link_libraries(CanvasTest PUBLIC gtest gtest_main)

