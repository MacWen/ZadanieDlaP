#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <string>
#include <vector>
#include "shape.h"
#include "triangle.h"
#include "rectangle.h"

enum ShapeEnum
{
  eTriangle,
  eRectangle
};

class ShapeFactory
{
public:
    ~ShapeFactory();
    static ShapeFactory* GetInstance();
    IShape* CreateShapeInstance(ShapeEnum a_eShape);
    bool IsFactoryChildren(IShape* a_oShapeObj);
    void Destroy();

private:
    ShapeFactory(){};
    static ShapeFactory* iInstance;
    std::vector<IShape*>children;
};

#endif /* SHAPEFACTORY_H */
