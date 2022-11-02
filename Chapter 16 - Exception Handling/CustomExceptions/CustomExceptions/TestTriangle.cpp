//
//  TestTriangle.cpp
//  CustomExceptions
//
//  Created by Brandon Kamplain on 4/2/22.
//

#include <iostream>
#include "GeometricObject.h"
#include "NonPositiveSideException.h"
#include "Triangle.h"
using namespace std;

/*int main()
{
    try
    {
        Triangle triangle;
        cout << "Perimeter is " << triangle.getPerimeter() << endl;
        cout << "Area is " << triangle.getArea() << endl;
        
        triangle.setSide3(4);
        cout << "Perimeter is " << triangle.getPerimeter() << endl;
        cout << "Area is " << triangle.getArea() << endl;
    }
    catch(TriangleException& ex)
    {
        cout << ex.what();
        cout << " three sides are " << ex.getSide1() << " " << ex.getSide2() << " " << ex.getSide3() << endl;
    }
    
    return 0;
}*/

int main()
{
  try
  {
    cout << "Enter three sides: ";
    double side1, side2, side3;
    cin >> side1 >> side2 >> side3;
    Triangle triangle(side1, side2, side3);
    cout << "Perimeter is " << triangle.getPerimeter() << endl;
    cout << "Area is " << triangle.getArea() << endl;
  }
  catch (NonPositiveSideException& ex)
  {
    cout << ex.what();
    cout << " the side is " << ex.getSide() << endl;
  }
  catch (TriangleException& ex)
  {
    cout << ex.what();
    cout << " three sides are " << ex.getSide1() << " "
      << ex.getSide2() << " " << ex.getSide3() << endl;
  }

  return 0;
}
