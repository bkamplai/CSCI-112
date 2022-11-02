//
//  Circle.cpp
//  CircleWithHeader
//
//  Created by Brandon Kamplain on 2/5/22.
//

#include "Circle.h"

int Circle::numberOfObjects = 0;

Circle::Circle()
{
    radius = 1;
    numberOfObjects++;
}

Circle::Circle(double newRadius)
{
    radius = newRadius;
    numberOfObjects++;
}

double Circle::getArea()
{
    return radius * radius * 3.14159;
}

double Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(double newRadius)
{
    radius = newRadius;
}

int Circle::getNumberOfObjects()
{
    return numberOfObjects;
}
