//
//  DerivedRectangle.h
//  TestPolymorphism
//
//  Created by Brandon Kamplain on 3/5/22.
//

#ifndef DerivedRectangle_h
#define DerivedRectangle_h
#include "GeometricObject.h"

class Rectangle : public GeometricObject
{
public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(double width, double height, const string& color, bool filled);
    double getWidth() const;
    void setWidth(double);
    double getHeight() const;
    void setHeight(double);
    double getArea() const;
    double getPerimeter() const;
    virtual string toString() const;
private:
    double width;
    double height;
}; // Must place semicolon here

#endif /* DerivedRectangle_h */
