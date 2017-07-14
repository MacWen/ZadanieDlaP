#include <iostream>
#include "shapefactory.h"
#include "shape.h"

using namespace std;

int main()
{
    ShapeFactory* myFactory = new ShapeFactory;

    IShape* myPolygon1 = myFactory->getPolygon("triangle");
    myPolygon1->setWidth(4);
    myPolygon1->setHeight(5);
    cout << myPolygon1->getArea() << endl;

    IShape* myPolygon2 = myFactory->getPolygon("rectangle");
    myPolygon2->setWidth(4);
    myPolygon2->setHeight(5);
    cout << myPolygon2->getArea() << endl;

    return 0;
}
