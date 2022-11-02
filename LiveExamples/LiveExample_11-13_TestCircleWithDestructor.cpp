#include <iostream>
#include "LiveExample_11-11_CircleWithDestructor.h"
using namespace std;

int main()
{
  Circle* pCircle1 = new Circle();
  Circle* pCircle2 = new Circle();
  Circle* pCircle3 = new Circle();

  cout << "Number of circle objects created: "
    << Circle::getNumberOfObjects() << endl;

  delete pCircle1; // Delete pCircle1

  cout << "Number of circle objects now is "
    << Circle::getNumberOfObjects() << endl;

  return 0;
}