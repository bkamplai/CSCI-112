#include <iostream>
#include "LiveExample_GeometricObjectWithVirtualtoString.h" // Virtual toString() 
#include "LiveExample_15-3_DerivedCircle.h"
#include "LiveExample_15-5_DerivedRectangle.h"

using namespace std;

void displayGeometricObject(const GeometricObject* g) // Pass a pointer
{
  cout << (*g).toString() << endl;
}

int main()
{
  displayGeometricObject(&GeometricObject());
  displayGeometricObject(&Circle(5));
  displayGeometricObject(&Rectangle(4, 6));

  return 0;
}