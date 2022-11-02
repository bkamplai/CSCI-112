#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
  Circle();
  Circle(double);
  double getArea() const; 
  // const instance member function
  double getRadius() const; 
  void setRadius(double);
  // No const for static member functions
  static int getNumberOfObjects(); 

private:
  double radius;
  static int numberOfObjects;
};

#endif