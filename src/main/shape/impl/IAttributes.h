#pragma once

#include<iostream>

struct IShapeAttributes {
    std::string description{};
    std::string menuSelector{};
    std::string commandParameters{};
    bool enable{true};

    ~IShapeAttributes() {}
};



