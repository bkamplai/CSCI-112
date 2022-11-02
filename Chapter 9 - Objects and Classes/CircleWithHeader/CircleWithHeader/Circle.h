//
//  Circle.h
//  CircleWithHeader
//
//  Created by Brandon Kamplain on 2/5/22.
//

class Circle
{

public:
    
    Circle();
    Circle(double);
    
    double getArea();
    double getRadius();
    void setRadius(double);
    
    static int getNumberOfObjects();
    
private:
    double radius;
    
    static int numberOfObjects;
    
};
