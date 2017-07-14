#include "shapefactory.h"

IShape* ShapeFactory::getPolygon(std::string type)
{
    if(type == "triangle") return new Triangle;
    if(type == "rectangle") return new Rectangle;
    return 0;
}
