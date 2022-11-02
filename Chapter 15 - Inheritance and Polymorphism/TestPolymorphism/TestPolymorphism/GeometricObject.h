//
//  GeometricObject.h
//  TestPolymorphism
//
//  Created by Brandon Kamplain on 3/5/22.
//

#ifndef GeometricObject_h
#define GeometricObject_h
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
private:
    string color;
    bool filled;
}; // Must place semicolon here

#endif /* GeometricObject_h */
