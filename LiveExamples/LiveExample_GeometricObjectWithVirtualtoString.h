#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
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
  virtual string toString() const; // Virtual toString()

private:
  string color;
  bool filled;
}; // Must place semicolon here

#endif 