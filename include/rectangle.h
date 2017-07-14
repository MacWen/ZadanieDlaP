#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public IShape
{
public:
    virtual double getArea();

    virtual void setWidth(double a_dWidth);
    virtual void setHeight(double a_dHeight);

    virtual double getWidth();
    virtual double getHeight();

    virtual ~Rectangle();
};

#endif /* RECTANGLE_H */
