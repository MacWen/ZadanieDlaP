#include <iostream>
#include <map>
#include "../external/tinyXML/tinyxml2.h"
#include "shapefactory.h"
#include "shape.h"

std::map<std::string, ShapeEnum> enumMap;
struct Params
{
    double width = 0.;
    double height = 0.;
    ShapeEnum eShapeType = eIncorrectShape;
};

bool CreateShapesFromXMLFile();
bool LoadXMLConfigFile(tinyxml2::XMLDocument* config);
bool CreateAndInitNewShapes(tinyxml2::XMLDocument* config);
void ResetParams(Params* oParams);
bool GetParametersForNextShape(tinyxml2::XMLElement* model, Params* oParams);
bool CreateAndInitShape(const Params& oParams);
void ShowMenu();
IShape* GetLastShape();
void MenuSelector();
void CreateNewShapeFromKeyboard();
void SetShapeWidth(IShape* shape);
void SetShapeHeight(IShape* shape);
double GetDoubleFromKeyboard();
IShape* ChooseDifferentShape();

bool CreateShapesFromXMLFile()
{
    bool bSuccess = false;

    tinyxml2::XMLDocument config;
    if(LoadXMLConfigFile(&config))
        bSuccess = CreateAndInitNewShapes(&config);

    return bSuccess;
}

bool LoadXMLConfigFile(tinyxml2::XMLDocument* config)
{
    bool bSuccess = false;

    if(config != NULL )
    {
        config->LoadFile("../resources/parameters.xml");

        if(config->ErrorID() == 0)
            bSuccess = true;
        else
            std::cout << "Unable to load parameters.xml file from /resources.\nClosing program..." << std::endl;
    }

    return bSuccess;
}

bool CreateAndInitNewShapes(tinyxml2::XMLDocument* config)
{
    bool bCreatedAtLeatsOneShape = false;

    if(config != NULL)
    {
        Params oParams;
        tinyxml2::XMLElement* model = config->FirstChildElement("Shape");
        while(model != NULL)
        {
            ResetParams(&oParams);

            if(GetParametersForNextShape(model, &oParams))
                bCreatedAtLeatsOneShape = CreateAndInitShape(oParams);

            model = model->NextSiblingElement("Shape");
        }
    }

    return bCreatedAtLeatsOneShape;
}

void ResetParams(Params* oParams)
{
    if(oParams != NULL)
    {
        oParams->eShapeType = eIncorrectShape;
        oParams->width = 0.;
        oParams->height = 0.;
    }
}

bool GetParametersForNextShape(tinyxml2::XMLElement* model, Params* oParams)
{
    bool bSuccess = false;

    if(oParams != NULL && model != NULL)
    {
        std::string shapeType(model->FirstChildElement("type")->GetText());
        oParams->eShapeType = enumMap[shapeType];
        model->FirstChildElement("parameters")->QueryDoubleAttribute("width", &oParams->width);
        model->FirstChildElement("parameters")->QueryDoubleAttribute("height", &oParams->height);

        if(oParams->eShapeType != 0 && oParams->width != 0 && oParams->height != 0)
            bSuccess = true;
        else
            std::cout << "Wrong parameters! Can't create new shape." << std::endl;
    }

    return bSuccess;
}

bool CreateAndInitShape(const Params& oParams)
{
    bool bCreatedAtLeatsOneShape = false;

    ShapeFactory* myFactory = ShapeFactory::GetInstance();
    if(myFactory != NULL)
    {
        IShape* tempShape = myFactory->CreateShapeInstance(oParams.eShapeType);
        if(tempShape != NULL)
        {
            bCreatedAtLeatsOneShape = true;
            tempShape->setWidth(oParams.width);
            std::cout << "New width set to " << oParams.width << std::endl;
            tempShape->setHeight(oParams.height);
            std::cout << "New height set to " << oParams.height << std::endl;
        }
    }

    return bCreatedAtLeatsOneShape;
}

void ShowMenu()
{
    std::cout << std::endl << "Type 1 if you want to add new shape" << std::endl;
    std::cout << "Type 2 if you want to select different shape" << std::endl;
    std::cout << "Type 3 if you want to see a shape area" << std::endl;
    std::cout << "Type 4 if you want to see actual widht" << std::endl;
    std::cout << "Type 5 if you want to see actual height" << std::endl;
    std::cout << "Type 6 if you want to set a new width" << std::endl;
    std::cout << "Type 7 if you want to set a new height" << std::endl;
    std::cout << "Type 9 if you want to see it again" << std::endl;
    std::cout << "Type 0 if you want to exit" << std::endl;
}

IShape* GetLastShape()
{
    IShape* shape = NULL;
    ShapeFactory* myFactory = ShapeFactory::GetInstance();
    if(myFactory != NULL)
    {
        shape = myFactory->GetLastShape();
    }
    return shape;
}

void MenuSelector()
{
    IShape* shape = GetLastShape();

    char menuItem;
    do
    {
        std::cin.get(menuItem);
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        switch(menuItem)
        {
            case '1':
                CreateNewShapeFromKeyboard();
                shape = GetLastShape();
                break;
            case '2':
                shape = ChooseDifferentShape();
                break;
            case '3':
                std::cout << "Shape area is: " << shape->getArea() << std::endl;
                break;
            case '4':
                std::cout << "Shape width is: " << shape->getWidth() << std::endl;
                break;
            case '5':
                std::cout << "Shape height is: " << shape->getHeight() << std::endl;
                break;
            case '6':
                SetShapeWidth(shape);
                break;
            case '7':
                SetShapeHeight(shape);
                break;
            case '9':
                ShowMenu();
                break;
            case '0':
                break;
            default:
                std::cout << "Undefined value. Try again." <<std::endl;
                ShowMenu();
                break;
        }
    }while(menuItem != '0');
}

void CreateNewShapeFromKeyboard()
{
    Params oParams;
    std::cout << std::endl << "Type 1 to create Rectangle";
    std::cout << std::endl << "Type 2 to create Triangle" << std::endl;
    char newShape;
    std::cin.get(newShape);
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    switch(newShape)
    {
        case '1':
            oParams.eShapeType = eRectangle;
            break;
        case '2':
            oParams.eShapeType = eTriangle;
            break;
        default:
            oParams.eShapeType = eIncorrectShape;
            std::cout << "Unrecognized shape" << std::endl;
            break;
    }

    if(oParams.eShapeType != eIncorrectShape)
    {
        std::cout << std::endl << "Type width:";
        oParams.width = GetDoubleFromKeyboard();
        std::cout << std::endl << "Type height:";
        oParams.height = GetDoubleFromKeyboard();
        CreateAndInitShape(oParams);
    }
}

void SetShapeWidth(IShape* oShape)
{
    std::cout << std::endl << "Type width:";
    double width = GetDoubleFromKeyboard();
    oShape->setWidth(width);
    std::cout << "Width set to " << width << std::endl;
}

void SetShapeHeight(IShape* oShape)
{
    std::cout << std::endl << "Type height:";
    double height = GetDoubleFromKeyboard();
    oShape->setHeight(height);
    std::cout << "Height set to " << height << std::endl;
}

double GetDoubleFromKeyboard()
{
    double dHeight;
    std::cin >> dHeight;
    if( std::cin.fail() || (std::cin.peek() != '\r' && std::cin.peek() != '\n'))
    {
        dHeight = 0;
        std::cout << "Wrong input!" << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    return dHeight;
}

IShape* ChooseDifferentShape()
{
    char ch;
    unsigned int number = 0;
    ShapeFactory* myFactory = ShapeFactory::GetInstance();
    if(myFactory != NULL)
    {
        std::cout << "You have " << myFactory->GetNumberOfShapes() << " shapes." << std::endl;
        std::cout << "Select a shape by typing it's number" << std::endl;
        myFactory->GetAllShapes();

        std::cin >> ch;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        number = ch - '0';
    }

    return (myFactory != NULL ? myFactory->SelectChild(number) : NULL);
}

int main()
{
    enumMap["Rectangle"] = ShapeEnum::eRectangle;
    enumMap["Triangle"] = ShapeEnum::eTriangle;

    try
    {
        if( CreateShapesFromXMLFile() )
        {
            ShowMenu();
            MenuSelector();
        }
        else
        {
            std::cout << "Can't create any object. Closing program..." << std::endl;
        }
    }
    catch(const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
