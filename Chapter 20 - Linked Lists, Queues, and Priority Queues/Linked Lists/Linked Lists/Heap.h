//
//  Heap.h
//  Linked Lists
//
//  Created by Brandon Kamplain on 3/26/22.
//

#ifndef Heap_h
#define Heap_h
#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class Heap
{
public:
  Heap();
  Heap(const T elements[], int arraySize);
  void add(const T& element);
  T remove();
  int getSize() const;

private:
  vector<T> v;
};

template<typename T>
Heap<T>::Heap()
{
}

template<typename T>
Heap<T>::Heap(const T elements[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    add(elements[i]);
  }
}

// Insert element into the heap and maintain the heap property
template<typename T>
void Heap<T>::add(const T& element)
{
  v.push_back(element); // Append element to the heap
  int currentIndex = v.size() - 1; // The index of the last node

  // Maintain the heap property
  while (currentIndex > 0)
  {
    int parentIndex = (currentIndex - 1) / 2;
    // Swap if the current element is greater than its parent
    if (v[currentIndex] > v[parentIndex])
    {
      T temp = v[currentIndex];
      v[currentIndex] = v[parentIndex];
      v[parentIndex] = temp;
    }
    else
      break; // the tree is a heap now

    currentIndex = parentIndex;
  }
}

// Remove the root from the heap
template<typename T>
T Heap<T>::remove()
{
  if (v.size() == 0)
    throw runtime_error("Heap is empty");

  T removedElement = v[0];
  v[0] = v[v.size() - 1]; // Copy the last to root
  v.pop_back(); // Remove the last element

  // Maintain the heap property
  int currentIndex = 0;
  while (currentIndex < v.size())
  {
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    // Find the maximum between two children
    if (leftChildIndex >= v.size()) break; // The tree is a heap
    int maxIndex = leftChildIndex;
    if (rightChildIndex < v.size())
    {
      if (v[maxIndex] < v[rightChildIndex])
      {
        maxIndex = rightChildIndex;
      }
    }

    // Swap if the current node is less than the maximum
    if (v[currentIndex] < v[maxIndex])
    {
      T temp = v[maxIndex];
      v[maxIndex] = v[currentIndex];
      v[currentIndex] = temp;
      currentIndex = maxIndex;
    }
    else
      break; // The tree is a heap
  }

  return removedElement;
}

// Get the number of element in the heap
template<typename T>
int Heap<T>::getSize() const
{
  return v.size();
}

#endif /* Heap_h */
