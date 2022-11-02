#include <iostream>
#include "LiveExample_15-1_GeometricObject.h"
#include "LiveExample_15-3_DerivedCircle.h"
#include "LiveExample_15-5_DerivedRectangle.h"

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