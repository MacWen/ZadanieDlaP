#include "rectangle.h"

double Rectangle::getArea()
{
    return (m_dWidth*m_dHeight);
}

void Rectangle::setWidth(double a_dWidth)
{
    m_dWidth=a_dWidth;
}

void Rectangle::setHeight(double a_dHeight)
{
    m_dHeight=a_dHeight;
}

double Rectangle::getWidth()
{
    return m_dWidth;
}

double Rectangle::getHeight()
{
    return m_dHeight;
}

Rectangle::~Rectangle(){}
