//
//  TestAbstractFunctions.cpp
//  AbstractClass
//
//  Created by Brandon Kamplain on 3/6/22.
//

#include <iostream>
#include "GeometricObject.hpp"
#include "DerivedCircle.hpp"
#include "DerivedRectangle.hpp"
using namespace std;

void displayGeometricObject(const GeometricObject& g)
{
    cout << "The area is " << g.getArea() << endl;
    cout << "The perimeter is " << g.getPerimeter() << endl;
}

void displayGeometricObject(GeometricObject& g)
{
  cout << "The area is " << g.getArea() << endl;
  cout << "The perimeter is " << g.getPerimeter() << endl;

  GeometricObject* p = &g;
  Circle* p1 = dynamic_cast<Circle*>(p);
  Rectangle* p2 = dynamic_cast<Rectangle*>(p);

  if (p1 != nullptr)
  {
    cout << "The radius is " << p1->getRadius() << endl;
    cout << "The diameter is " << p1->getDiameter() << endl;
  }

  if (p2 != nullptr)
  {
    cout << "The width is " << p2->getWidth() << endl;
    cout << "The height is " << p2->getHeight() << endl;
  }
}

bool equalArea(const GeometricObject& g1, const GeometricObject& g2)
{
    return g1.getArea() == g2.getArea();
}

int main()
{
    Circle circle(5);
    Rectangle rectangle(5, 3);
    
    //GeometricObject g; // Error: "Variable type 'GeometricObject' is an abstract class"
    
    cout << "Circle info: " << endl;
    displayGeometricObject(circle);
    
    cout << "\nRectangle info: " << endl;
    displayGeometricObject(rectangle);
    
    cout << "\nThe two objects have the same area? " << (equalArea(circle, rectangle) ? "yes" : "no") << endl;
    
    return 0;
}
