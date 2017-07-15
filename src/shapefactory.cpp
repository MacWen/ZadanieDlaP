#include <iostream>
#include "shapefactory.h"

ShapeFactory* ShapeFactory::iInstance = NULL;

ShapeFactory* ShapeFactory::GetInstance()
{
    if(iInstance == NULL)
        iInstance = new ShapeFactory();

    return iInstance;
}

IShape* ShapeFactory::CreateShapeInstance(ShapeEnum a_eShape)
{
    if(a_eShape == eTriangle)
        children.push_back(new Triangle);
    if(a_eShape == eRectangle)
        children.push_back(new Rectangle);

    return children.back();
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
