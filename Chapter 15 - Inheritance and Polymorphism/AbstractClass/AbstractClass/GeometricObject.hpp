//
//  GeometricObject.hpp
//  AbstractClass
//
//  Created by Brandon Kamplain on 3/6/22.
//

#ifndef GeometricObject_hpp
#define GeometricObject_hpp

#include <string>
using namespace std;

class GeometricObject
{
public:
    GeometricObject();
    GeometricObject(const string& color, bool filled);
    string getColor() const;
    void setColor(const string& color);
    bool isFilled() const;
    void setFilled(bool filled);
    virtual string toString() const;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
private:
    string color;
    bool filled;
}; // Must place semicolon here

#endif /* GeometricObject_hpp */
