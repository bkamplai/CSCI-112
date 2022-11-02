//
//  PriorityQueue.h
//  Linked Lists
//
//  Created by Brandon Kamplain on 3/26/22.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h
#include "Heap.h"

template<typename T>
class PriorityQueue
{
public:
  PriorityQueue();
  void enqueue(const T& element);
  T dequeue();
  int getSize() const;

private:
  Heap<T> heap;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
}

template<typename T>
void PriorityQueue<T>::enqueue(const T& element)
{
  heap.add(element);
}

template<typename T>
T PriorityQueue<T>::dequeue()
{
  return heap.remove();
}

template<typename T>
int PriorityQueue<T>::getSize() const
{
  return heap.getSize();
}

#endif /* PriorityQueue_h */
