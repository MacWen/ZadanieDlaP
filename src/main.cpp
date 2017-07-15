#include <iostream>
#include "shapefactory.h"
#include "shape.h"

int main()
{
    try
    {
        ShapeFactory* myFactory = ShapeFactory::GetInstance();
        if(myFactory != NULL)
        {
            IShape* myPolygon1 = myFactory->CreateShapeInstance(eTriangle);
            if(myPolygon1 != NULL)
            {
                if(myFactory->IsFactoryChildren(myPolygon1))
                {
                    myPolygon1->setWidth(4);
                    myPolygon1->setHeight(5);
                    std::cout << myPolygon1->getArea() << std::endl;
                }
                else
                    std::cout << "It's not a Factory child!" << std::endl;
            }
            else
                std::cout << "Something is \"no yes\"!" << std::endl;

            myFactory->Destroy();

            IShape* myPolygon2 = myFactory->CreateShapeInstance(eRectangle);
            if(myPolygon2 != NULL)
            {
                if(myFactory->IsFactoryChildren(myPolygon2))
                {
                    myPolygon2->setWidth(4);
                    myPolygon2->setHeight(5);
                    std::cout << myPolygon2->getArea() << std::endl;
                }
                else
                    std::cout << "It's not a Factory child!" << std::endl;
            }
            else
                std::cout << "Something is \"no yes\"!" << std::endl;

            IShape* myPolygon3 = new Rectangle;
            if(myPolygon3 != NULL)
            {
                if(myFactory->IsFactoryChildren(myPolygon3))
                {
                    myPolygon3->setWidth(4);
                    myPolygon3->setHeight(5);
                    std::cout << myPolygon3->getArea() << std::endl;
                }
                else
                    std::cout << "It's not a Factory child!" << std::endl;
            }
            else
                std::cout << "Something is \"no yes\"!" << std::endl;

            IShape* myPolygon4 = myPolygon2;
            if(myPolygon4 != NULL)
            {
                if(myFactory->IsFactoryChildren(myPolygon4))
                {
                    std::cout << myPolygon4->getArea() << std::endl;
                }
                else
                    std::cout << "It's not a Factory child!" << std::endl;
            }

            myFactory->Destroy();
            delete myPolygon3;
            myPolygon1 = NULL;
            myPolygon2 = NULL;
            myPolygon4 = NULL;
        }
        else
            std::cout << "Can't create a Factory!" << std::endl;
    }
    catch(const std::exception& ex)
    {
      std::cerr << ex.what() << std::endl;
      return 1;
    }

    return 0;
}
