//
//  DerivedCircle.h
//  TestPolymorphism
//
//  Created by Brandon Kamplain on 3/5/22.
//

#ifndef DerivedCircle_h
#define DerivedCircle_h
#include "GeometricObject.h"

class Circle: public GeometricObject
{
public:
  Circle();
  Circle(double);
  Circle(double radius, const string& color, bool filled);
  double getRadius() const;
  void setRadius(double);
  double getArea() const;
  double getPerimeter() const;
  double getDiameter() const;
  virtual string toString() const;

private:
  double radius;
}; // Must place semicolon here

#endif /* DerivedCircle_h */
