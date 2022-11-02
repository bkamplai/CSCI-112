#include "LiveExample_15-1_GeometricObject.h"
#include "LiveExample_15-3_DerivedCircle.h"
#include "LiveExample_15-5_DerivedRectangle.h"
#include <iostream>
using namespace std;

int main()
{
  GeometricObject shape;
  shape.setColor("red");
  shape.setFilled(true);
  cout << shape.toString() << endl
    << " color: " << shape.getColor()
    << " filled: " << (shape.isFilled() ? "true" : "false") << endl; 

  Circle circle(5);
  circle.setColor("black");
  circle.setFilled(false);
  cout << circle.toString()<< endl
    << " color: " << circle.getColor()
    << " filled: " << (circle.isFilled() ? "true" : "false") 
    << " radius: " << circle.getRadius()
    << " area: " << circle.getArea()
    << " perimeter: " << circle.getPerimeter() << endl;

  Rectangle rectangle(2, 3);
  rectangle.setColor("orange");
  rectangle.setFilled(true);
  cout << rectangle.toString()<< endl
	<< " color: " << rectangle.getColor()
    << " filled: " << (rectangle.isFilled() ? "true" : "false")
    << " width: " << rectangle.getWidth()
    << " height: " << rectangle.getHeight()
    << " area: " << rectangle.getArea()
    << " perimeter: " << rectangle.getPerimeter() << endl;

  return 0;
}