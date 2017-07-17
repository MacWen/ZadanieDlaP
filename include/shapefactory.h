#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <string>
#include <vector>
#include "shape.h"
#include "triangle.h"
#include "rectangle.h"

enum ShapeEnum
{
  eTriangle=1,
  eRectangle,

  eIncorrectShape
};

class ShapeFactory
{
public:
    ~ShapeFactory();
    static ShapeFactory* GetInstance();
    IShape* CreateShapeInstance(ShapeEnum a_eShape);
    IShape* GetLastShape();
    int GetNumberOfShapes();
    void GetAllShapes();
    IShape* SelectChild(unsigned int number);
    bool IsFactoryChildren(IShape* a_oShapeObj);
    void Destroy();

private:
    ShapeFactory(){};
    static ShapeFactory* iInstance;
    std::vector<IShape*>children;
};

#endif /* SHAPEFACTORY_H */
