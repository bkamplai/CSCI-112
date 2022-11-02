//
//  TestCircle.cpp
//  CircleWithHeader
//
//  Created by Brandon Kamplain on 2/5/22.
//

#include <iostream>

using namespace std;

#include "Circle.h"

int main()
{
    
    Circle circle1;
    Circle circle2(5.0);
    
    cout << "The area of the circle of radius " << circle1.radius << " is " << circle1.getArea() << endl;
    cout << "The area of the circle of radius " << circle2.radius << " is " << circle2.getArea() << endl;
    
    circle2.radius = 100;
    
    cout << "The area of the circle of radius " << circle2.radius << " is " << circle2.getArea() << endl;
    
    return 0;
}
