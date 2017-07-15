#ifndef SHAPE_H
#define SHAPE_H

class IShape
{
public:
    virtual double getArea() = 0;

    virtual void setWidth(double a_dWidth) = 0;
    virtual void setHeight(double a_dHeight) = 0;

    virtual double getWidth() = 0;
    virtual double getHeight() = 0;

    virtual ~IShape(){};

protected:
    double m_dWidth;
    double m_dHeight;
};

#endif /* SHAPE_H */
