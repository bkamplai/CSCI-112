//
//  main.cpp
//  Chapter15ProgrammingProject
//  Exercise 15_03
//  (Extended MyPoint)
//
//  Created by Brandon Kamplain on 3/6/22.
//
/* Instructions:
 In Programming Exercise 9.4, the MyPoint class was created to model a point in a two-dimensional plane. The MyPoint class has the properties x and y that represent x- and y-coordinates, two getter functions for x and y, and the function for returning the distance between two points.
 Define a class named ThreeDPoint to model a point in a three-dimensional space. Let ThreeDPoint be derived from MyPoint with the following additional features:
 - A data field named z that represents the z-coordinate.
 - A no-arg constructor that constructs a point with coordinates (0, 0, 0).
 - A constructor that constructs a point with three specified coordinates.
 - A constant getter function that returns the z value.
 - A constant distance(const MyPoint&) function to return the distance between this point and the other point in the three-dimensional space.
 Implement the class. Write a test program that creates two points (0, 0, 0) and (10, 30, 25.5) and displays the distance between them.
 Use the code from https://liangcpp.pearsoncmg.com/test/Exercise15_03.txt to complete your program.
 For a hint on this program, please see https://liangcpp.pearsoncmg.com/cpprevel2e.html.
 If you get a logic or runtime error, please refer to https://liangcpp.pearsoncmg.com/faq.html. */

#include <iostream>
#include <cmath>
using namespace std;

class MyPoint
{
private:
  double x;
  double y;

public:
  MyPoint()
  {
    x = y = 0;
  }

  MyPoint(double x, double y)
  {
    this->x = x;
    this->y = y;
  }
    
   void setX(double x)
    {
       this->x = x;
    }
    
    void setY(double y)
    {
        this->y = y;
    }

  double distance(const MyPoint& p2) const
  {
    return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
  }

  double getX() const
  {
    return x;
  }

  double getY() const
  {
    return y;
  }
};

class ThreeDPoint: public MyPoint
{
private:
  double z;

public:
  ThreeDPoint()
    {
        MyPoint();
        z = 0;
    }
  ThreeDPoint(double x, double y, double z)
    {
      setX(x);
      setY(y);
        this->z = z;
    }
  double getZ() const
    {
        return z;
    }
  double distance(const ThreeDPoint& p2)
    {
      return sqrt((getX()-p2.getX())*(getX()-p2.getX())+(getY()-p2.getY())*(getY()-p2.getY())+(z-p2.z)*(z-p2.z));
    }
};

// Write the code to implement the constructors and functions in ThreePoint

int main()
{
  // Write code here in the main function
    
    ThreeDPoint p1;
    ThreeDPoint p2(10, 30, 25.5);
    
    cout << p1.distance(p2) << endl;
    
  return 0;
}
