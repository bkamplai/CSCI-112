//
//  TestStaticCircle.cpp
//  CircleWithHeader
//
//  Created by Brandon Kamplain on 2/13/22.
//

#include <iostream>
using namespace std;

#include "Circle.h"

int main()
{
/*
    cout << "The number of cirlce objects created: " << Circle::getNumberOfObjects() << endl;
    
    Circle circle1;
    
    cout << "The area of the cirlce of radius " << circle1.getRadius() << " is " << circle1.getArea() << endl;
    
    cout << "The number of cirlce objects created: " << Circle::getNumberOfObjects() << endl;
    
    Circle circle2(5);
    
    cout << "The area of the cirlce of radius " << circle2.getRadius() << " is " << circle2.getArea() << endl;
    
    cout << "The number of cirlce objects created: " << Circle::getNumberOfObjects() << endl;
    
    Circle circle3(3.3);
    
    cout << "The area of the cirlce of radius " << circle3.getRadius() << " is " << circle3.getArea() << endl;
    
    cout << "The number of cirlce objects created: " << Circle::getNumberOfObjects() << endl;
*/
    cout << Circle(5).getArea() << endl;
    cout << (new Circle(5))->getArea() << endl;
    
    return 0;
}
