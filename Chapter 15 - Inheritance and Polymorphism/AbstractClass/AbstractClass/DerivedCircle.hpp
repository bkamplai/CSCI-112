//
//  DerivedCircle.hpp
//  AbstractClass
//
//  Created by Brandon Kamplain on 3/6/22.
//

#ifndef DerivedCircle_hpp
#define DerivedCircle_hpp

#include "GeometricObject.hpp"

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


#endif /* DerivedCircle_hpp */
