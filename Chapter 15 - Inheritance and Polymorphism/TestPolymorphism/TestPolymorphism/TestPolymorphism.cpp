//
//  TestPolymorphism.cpp
//  TestPolymorphism
//
//  Created by Brandon Kamplain on 3/5/22.
//

#include <iostream>
#include "GeometricObject.h"
#include "DerivedCircle.h"
#include "DerivedRectangle.h"
using namespace std;

void displayGeometricObject(const GeometricObject& g)
{
    cout << g.toString() << endl;
}

int main()
{
    GeometricObject geometricObject;
    displayGeometricObject(geometricObject);
    
    Circle circle(5);
    displayGeometricObject(circle);
    
    Rectangle rectangle(4, 6);
    displayGeometricObject(rectangle);
    
    return 0;
}
