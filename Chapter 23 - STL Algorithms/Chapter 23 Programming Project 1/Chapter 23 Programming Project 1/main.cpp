//
//  main.cpp
//  Chapter 23 Programming Project 1
//
//  Created by Brandon Kamplain on 5/7/22.
//

// Search for "WRITE YOUR CODE" to complete this program
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

template <typename ForwardIterator, typename function>
void generate(ForwardIterator beg, ForwardIterator end, function gen);

template <typename ForwardIterator, typename function>
void generate(ForwardIterator beg, ForwardIterator end, function gen)
{
  // WRITE YOUR CODE
}

template <typename ForwardIterator, typename size, typename function>
void generate_n(ForwardIterator beg, size n, function gen);

template <typename ForwardIterator, typename size, typename function>
void generate_n(ForwardIterator beg, size n, function gen)
{
  // WRITE YOUR CODE
}

int nextNum()
{
  static int n = 20;
  return n++;
}

int main()
{
  int values[6] = {0};
  cout << "Enter six integers: ";
  for (unsigned i = 0; i < 6; i++)
    cin >> values[i];
  
  list<int> intList(values, values + 6);

  ostream_iterator<int> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 6, output);
  cout << "\nInitial contents, intList: ";
  copy(intList.begin(), intList.end(), output);

  generate(values + 2, values + 4, nextNum);
  generate_n(intList.begin(), 2, nextNum);

  cout << "\nAfter the generate function, values: ";
  copy(values, values + 6, output);
  cout << "\nAfter the generate_n function, intList: ";
  copy(intList.begin(), intList.end(), output);

  return 0;
}
