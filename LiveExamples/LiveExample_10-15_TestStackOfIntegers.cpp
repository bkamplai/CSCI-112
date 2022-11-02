#include <iostream>
#include "LiveExample_10-14_StackOfIntegers.h"
using namespace std;

int main()
{
  StackOfIntegers stack;

  for (int i = 0; i < 10; i++)
    stack.push(i);

  while (!stack.empty())
    cout << stack.pop() << " ";

  return 0;
}