#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <string>
#include "shape.h"
#include "triangle.h"
#include "rectangle.h"

class ShapeFactory
{
public:
    IShape* getPolygon(std::string type);
};

#endif /* SHAPEFACTORY_H */
