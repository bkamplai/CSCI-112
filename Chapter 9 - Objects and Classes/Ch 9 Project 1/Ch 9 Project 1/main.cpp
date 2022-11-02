//
//  main.cpp
//  Ch 9 Project 1
//
//  Created by Brandon Kamplain on 2/6/22.
//
/*
Instructions:
(The Rectangle class)
Design a class named "Rectangle" to represent a rectangle. The class contains:
- Two double data fields named "width" and "height" that specify the width and height of the rectangle.
- A no-arg constructor that creates a rectangle with width 1 and height 1.
- The accessor and mutator functions for all the data fields.
- A function named "getArea()" that returns the area of this rectangle.
- A function named "getPerimeter()" that reurns the perimeter.
Implement the class. Write a test program that creates two Rectangle objects. Assign width 4 and height 40 to the first object and width 3.5 and height 35.9 to the second. Display the width, height, area, and perimeters of the first object and then the second object. Use the code from https://liangcpp.pearsoncmg.com/test/Exercise09_01.txt to complete your program. For a hint on this program, please see https://liangcpp.pearsoncmg.com/cpprevel2e.html. If you get a logic or runtime error, please refer to https://liangcpp.pearsoncmg.com/faq.html.
*/

#include <iostream> // Exercise09_01
using namespace std;

class Rectangle
{
public:
    double width, height;
    
    Rectangle()
    {
        width = 1;
        height = 1;
    }
    
    Rectangle(double newWidth, double newHeight)
    {
        width = newWidth;
        height = newHeight;
    }
    
    double getArea()
    {
        return width * height;
    }
    
    double getPerimeter()
    {
        return (2 * width) + (2 * height);
    }
};

// Implement the header here

int main() {
    
    Rectangle rectangle1;
    Rectangle rectangle2(4, 40);
    Rectangle rectangle3(3.5, 35.9);
    
    cout << "The area of the rectangle of width " << rectangle1.width << " and height " << rectangle1.height << " is " << rectangle1.getArea() << " with a perimeter of " << rectangle1.getPerimeter() << endl;
    cout << "The area of the rectangle of width " << rectangle2.width << " and height " << rectangle2.height << " is " << rectangle2.getArea() << " with a perimeter of " << rectangle2.getPerimeter() << endl;
    cout << "The area of the rectangle of width " << rectangle3.width << " and height " << rectangle3.height << " is " << rectangle3.getArea() << " with a perimeter of " << rectangle3.getPerimeter() << endl;

    return 0;
}
