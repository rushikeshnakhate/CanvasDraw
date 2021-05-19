#pragma once

#include "impl/IAttributes.h"
#include "../canvaspage/ICanvasPage.h"
#include "../common/Utils.h"
#include "../common/Model.h"

class IShape {

public:

    virtual ~IShape() = default;

    virtual IShapeAttributes &getAttributes() = 0;

    virtual bool validateCommand(std::vector<std::string> &requestItems) = 0;

    virtual bool validateShapeConstraints(std::vector<std::string> &requestItems) = 0;

    virtual CanvasPage getBuildCanvas(std::vector<std::string> &requestItems) = 0;


};
