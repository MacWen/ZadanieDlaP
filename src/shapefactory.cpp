#include <iostream>
#include "shapefactory.h"

ShapeFactory* ShapeFactory::iInstance = NULL;

ShapeFactory* ShapeFactory::GetInstance()
{
    if(iInstance == NULL)
        iInstance = new ShapeFactory();

    if(iInstance == NULL)
        std::cout << "Can't create a Factory!\nClosing program..." << std::endl;

    return iInstance;
}

IShape* ShapeFactory::CreateShapeInstance(ShapeEnum a_eShape)
{
    if(a_eShape == eTriangle)
    {
        children.push_back(new Triangle);
        std::cout << "New triangle created." << std::endl;
    }
    else if(a_eShape == eRectangle)
    {
        children.push_back(new Rectangle);
        std::cout << "New rectangle created" << std::endl;
    }
    else
    {
        std::cout << "Couldn't create a shape." << std::endl;
        return NULL;
    }

    return children.back();
}

IShape* ShapeFactory::GetLastShape()
{
    return children.back();
}

int ShapeFactory::GetNumberOfShapes()
{
    return children.size();
}

void ShapeFactory::GetAllShapes()
{
    int itemNumber = 0;
    for(std::vector<IShape*>::iterator it = children.begin() ; it != children.end(); ++itemNumber, ++it)
    {
        if(dynamic_cast<Triangle*>(*it))
            std::cout << itemNumber << ". Triangle, ";
        else if(dynamic_cast<Rectangle*>(*it))
            std::cout << itemNumber << ". Rectangle, ";
        std::cout << "width: " << (*it)->getWidth() << ", height: " << (*it)->getHeight() << std::endl;
    }
}

IShape* ShapeFactory::SelectChild(unsigned int number)
{
    if(number < children.size())
    {
        std::cout << "Object nr " << number << " selected." << std::endl;
        return children[number];
    }
    else
    {
        std::cout << "Can't find that object object. First object selected." << std::endl;
        return children[0];
    }
}

bool ShapeFactory::IsFactoryChildren(IShape* a_oShapeObj)
{
    bool bIsFactoryChildren = false;
    for(std::vector<IShape*>::iterator it = children.begin() ; it != children.end(); ++it)
    {
        if(*it == a_oShapeObj)
        {
            bIsFactoryChildren = true;
            break;
        }
    }
    return bIsFactoryChildren;
}

void ShapeFactory::Destroy()
{
    try
    {
        for(std::vector<IShape*>::iterator it = children.begin() ; it != children.end(); ++it)
            delete (*it);

        children.clear();
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

ShapeFactory::~ShapeFactory()
{
    Destroy();
    delete iInstance;
}
