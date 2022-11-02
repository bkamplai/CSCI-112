#include <iostream>
using namespace std;

int main()
{
  int list[6] = {11, 12, 13, 14, 15, 16};
  int* p = list; // Assign array list to pointer p

  for (int i = 0; i < 6; i++)
    cout << "address: " << (list + i) <<
      " value: " << *(list + i) << " " <<
      " value: " << list[i] << " " <<
      " value: " << *(p + i) << " " <<
      " value: " << p[i] << endl;

  return 0;
}