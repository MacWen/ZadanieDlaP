#include "triangle.h"

double Triangle::getArea()
{
    return (m_dWidth*m_dHeight/2);
}

void Triangle::setWidth(double a_dWidth)
{
    m_dWidth=a_dWidth;
}

void Triangle::setHeight(double a_dHeight)
{
    m_dHeight=a_dHeight;
}

double Triangle::getWidth()
{
    return m_dWidth;
}

double Triangle::getHeight()
{
    return m_dHeight;
}

Triangle::~Triangle(){}
