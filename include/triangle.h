#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle: public IShape
{
public:
    virtual double getArea();

    virtual void setWidth(double a_dWidth);
    virtual void setHeight(double a_dHeight);

    virtual double getWidth();
    virtual double getHeight();

    virtual ~Triangle();
};

#endif /* TRIANGLE_H */
