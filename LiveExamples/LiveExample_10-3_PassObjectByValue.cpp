#include <iostream>
// CircleWithPrivateDataFields.h is defined in Section 9.9
#include "LiveExample_9-9_CircleWithPrivateDataFields.h" 
using namespace std;

void printCircle(Circle c) // Pass a Circle object by value
{
  cout << "The area of the circle of "
    << c.getRadius() << " is " << c.getArea() << endl;
}

int main()
{
  Circle myCircle(5.0);
  printCircle(myCircle); 

  return 0;
}