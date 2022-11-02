#include <iostream>
#include "LiveExample_14-4_Date.h"
using namespace std;

class AccessDate
{
public:
  static void p()
  {
    Date birthDate(2010, 3, 4);
    birthDate.year = 2000; // Access private data in Date
    cout << birthDate.year << endl;
  }
};

int main()
{
  AccessDate::p(); // Invoke p() in AccessDate

  return 0;
}